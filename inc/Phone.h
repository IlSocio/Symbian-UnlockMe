
/*
 TODO:Trasformarla in singleton
 Interagisce con il cell a basso livello utilizzando etelmm
*/


#ifndef __PHONE_H__
#define __PHONE_H__

#include <etel3rdparty.h>
#include <e32base.h>
//#include <etelmm.h>
#include <msvapi.h>
#include <mmretrieve.h> // CRetrieveMobilePhoneSmspList
#include "timeouttimer.h"
#include "timeoutnotifier.h"
// #include <smsclnt.h>  // CSmsClientMtm
// #include <mtclreg.h>  // CClientMtmRegistry
#include <MdaAudioTonePlayer.h>


#define KSCA_LEN 20


class MLockHandler 
	{
	public:
		virtual void CompletedL(TBool found, const TDesC& code, const TInt error)=0;
	};


/** Classe per la gestione a basso livello del telefono */
class CPhone : public CActive, public MMsvSessionObserver, public MTimeOutNotifier, public MMdaAudioToneObserver
	{


	enum TAppStatus 
		{
		EHandle_Init,
		EHandle_ChangeCode,
		EWait,
		EStop
		};

	public:
		RMobilePhone iPhone;
		RMobilePhone::TMobilePhoneNetworkInfoV1 iNetInfo;

		CPhone();
		virtual ~CPhone();

		void TimerExpiredL();

		/** Inizializza il telefono da richiamare prima di tutto */
		void InitializeL(MLockHandler& aHandler);

		void StartUnlock(int i);
		void EndUnlock();

		void MatoPrepareComplete(TInt aError);
		void MatoPlayComplete(TInt aError);

		virtual void HandleSessionEventL(TMsvSessionEvent aEvent, TAny* aArg1, TAny* aArg2, TAny* aArg3);
		void DoChangeCode(const TDesC& oldCode, const TDesC& newCode);
		void DoChangeCode(const TInt oldCode, const TDesC& newCode);
		void TryNextCode();

	private:

		/**	Resistuisce il nome del tsy che gestisce il telefono */
		void GetPhoneTsyL(TDes& aTsy);

		void DoVerifyCode(const TDesC& code);

		// from CActive
		TInt RunError(TInt aError);
		void RunL();
		void DoCancel();

	private:
		CMdaAudioToneUtility* iPlayer;
		RMobilePhone::TMobilePhonePasswordChangeV1 iPassChange;
		TBuf<10> iCodeStr;
		TInt iCode;
		TBuf<20> iTsyName;
		CTimeOutTimer* iTimer;
		RTelServer iServer;
		TAppStatus iAppStatus;
		RMobilePhone::TMobilePhoneRegistrationStatus iRegStatus;
		MLockHandler* iHandler;
		RMobilePhone::TMobilePhoneNetworkInfoV1Pckg infoPkg;
	};


#endif



