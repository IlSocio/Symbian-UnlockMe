
#ifndef __STORAGE_H__
#define __STORAGE_H__

#include <e32std.h>
#include <s32strm.h>
#include <f32file.h>

	_LIT(KFileSettings,"\\system\\apps\\FlashSms\\FlashSms.dat");
	_LIT(KYes, "Yes");
	_LIT(KNo, "No");
	_LIT(KVERSION, "1.0");


	enum { KIMEI_LEN = 20 };


struct TFlashSmsSettings 
	{
	TBuf<3>				version;
	TBuf<KIMEI_LEN> 	regCode;
	TBuf<KIMEI_LEN> 	imei;


	void Default() 
		{
		version = KVERSION;
		regCode.Zero();
		imei.Zero();
		}


	// Restituisce il RegRequestCode che viene ricavato dal codice imei
	HBufC* GetRegRequestCodeLC() const
	{   // RegReq: w5j6khM2
/*		HBufC* buff = HBufC::NewLC(20);
		TPtr ptr = buff->Des();
		ptr.Append( TChar(195) );
		ptr.Append( TChar(152) );
		ptr.Append( TChar(250) );
		ptr.Append( TChar(146) );
 		ptr.Append( TChar(19) );
		ptr.Append( TChar(54) );
		return buff; */
		// riduce il codice imei in 6 bytes prendendo solo quelli relativi al deviceid
		TBuf<7> tmp;
		tmp = imei.Right(7); // 289318
		tmp.SetLength(6);
		return GetRegRequestCodeLC(tmp);
	}


	void Ror(TDes& data) const 
	{
		TInt oldResto=0;
		for (TInt i=0; i<data.Length(); i++) 
		{
			TInt resto=0;
			if (data[i] % 2 == 1) resto=0x80;
			data[i] = (TUint16)((data[i]>>1) +oldResto);
			oldResto = resto;
		}
		data[0] = (TUint16)(data[0]+oldResto);		
	}

	
	// Prende in input 6 bytes e restituisce altri 6 bytes
	// Restituisce il RegRequestCode che viene ricavato dalla sorgente
	HBufC* GetRegRequestCodeLC(const TDesC& data) const
		{
		HBufC* buff = HBufC::NewLC( data.Length() );
		TPtr ptr = buff->Des();
		ptr.Append( data );
		TInt tot=0;
		for (TInt i=0; i<data.Length(); i++) 
		{
			tot += data[i];
			tot %= 110;
		}
		for (TInt j=0; j<ptr.Length(); j++) 
		{
			Ror(ptr);
			TInt val = (tot + (j+1)*18) % 256;
			val ^= ptr[j];
			ptr[j] = (TUint16) val;
		}
		return buff;
		}
	
	
	// Restituisce True se il RegCode impostato e' corretto per il codice imei impostato
	TBool IsValidRegCodeL() const
	{
		if (regCode.Length()<5) return EFalse;
		if (imei.Length()<5) return EFalse;
		HBufC* regReqCode = GetRegRequestCodeLC();
		HBufC* good       = GetRegRequestCodeLC( *regReqCode );
		bool valid = false;
		if ( *good == regCode ) valid = true;
		CleanupStack::PopAndDestroy(2);
		return valid;
	}


	
	void Crypt(const TDesC& buf, TDes& out) const
		{
		TUint8 key = (TUint8) buf.Length();
		out.Zero();
		TBuf8<KIMEI_LEN> tmp;
		tmp.Copy(buf);
		for (int i=0; i<tmp.Length(); i++) 
			{
			TUint8 num = tmp.Ptr()[i];
			num = (TUint8) (num ^ (key+i+141));
			tmp[i] = num;
			}
		out.Copy(tmp);
		}


	void CryptAndExtL(RWriteStream& aStream, const TDesC& src) const
		{
		TBuf<KIMEI_LEN> out;
		Crypt(src, out);
		aStream << out;
		}


	void CryptAndExtL(RWriteStream& aStream, const TBool flag) const
		{
		TBuf<KIMEI_LEN> out;
		if (flag) 
			Crypt(KYes, out);
		else 
			Crypt(KNo, out);
		aStream << out;
		}


	void ExternalizeL(RWriteStream& aStream) const
		{
		CryptAndExtL(aStream, version);
		CryptAndExtL(aStream, regCode);
		CryptAndExtL(aStream, imei);
		}


	void IntAndDeCryptL(RReadStream& aStream, TDes& out) const
		{
		TBuf<KIMEI_LEN> tmp;
		tmp.Zero();
		aStream >> tmp;
		Crypt(tmp, out);
		}


	TBool IntAndDeCryptL(RReadStream& aStream) const
		{
		TBuf<KIMEI_LEN> tmp;
		TBuf<KIMEI_LEN> out;
		aStream >> tmp;
		Crypt(tmp, out);
		if (out == KYes) return ETrue;
		return EFalse;
		}


	void InternalizeL(RReadStream& aStream) 
		{
		IntAndDeCryptL(aStream, version);
		IntAndDeCryptL(aStream, regCode);
		IntAndDeCryptL(aStream, imei);
		if (version != KVERSION) 
			{
			Default();
			}
		}
	};



class CStorage : public CBase
	{
	public:
        static CStorage* NewL(RFs& fsSession, const TDesC& drive);
		
		void SaveSettingsL();
		
		/** Se restituisce un valore != 0 significa che i settings
		    non erano presenti e sono stati creati */
		TInt LoadSettingsL();
		void ResetSettingsL();
	protected:
		void ConstructL(RFs& fsSession, const TDesC& appPath);

	public:
		TFlashSmsSettings iSettings;
		TBuf<80>	iDatFile;
		RFs*		iFs;
	};


#endif