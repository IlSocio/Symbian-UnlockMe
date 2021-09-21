/*#ifdef __WINS__
	_LIT(KEmulatorImei, "123456789012345");
#endif*/

#include <f32file.h>
//#include <etelmm.h>
#include <Commdb.h>
#include "Phone.h"
#include <gsmuetel.h>
#include <gsmumsg.h>
#include <gsmubuf.h>
#include <smuthdr.h>
#include <txtfmlyr.h>
#include <txtrich.h>
#include <es_sock.h>
#include <smsuaddr.h>
#include <smsustrm.h>
#include <mtclreg.h>
#include <SMSCLNT.h>
//#include <etel3rdparty.h>

//#include <stdio.h>



CPhone::CPhone() : CActive(EPriorityStandard), infoPkg(iNetInfo)
	{
	CActiveScheduler::Add( this );
	iAppStatus = EHandle_Init;
	}


CPhone::~CPhone() 
	{
	Cancel();
	if (iPlayer)
		delete iPlayer;
	if (iTimer)
		delete iTimer;

	iPhone.Close();
	if (iTsyName.Length()>0) 
		iServer.UnloadPhoneModule(iTsyName);
	iServer.Close();
	}


TInt CPhone::RunError(TInt aError) 
	{
	Cancel();
	return aError;
	}


void CPhone::InitializeL(MLockHandler& aHandler)
	{
	iHandler = &aHandler;
	User::LeaveIfError(iServer.Connect());

	GetPhoneTsyL(iTsyName);	
	User::LeaveIfError(iServer.LoadPhoneModule(iTsyName));

	// Get the details for the first (and only) phone.
	RTelServer::TPhoneInfo info;
	User::LeaveIfError(iServer.GetPhoneInfo(0, info));

	// Open the phone.
	User::LeaveIfError(iPhone.Open(iServer, info.iName));

	iPlayer = CMdaAudioToneUtility::NewL(*this);
	iTimer = CTimeOutTimer::NewL(EPriorityStandard, *this);
	}


void CPhone::StartUnlock(int i) 
{
	iCode = i;
	DoChangeCode(iCode, _L("12345"));
	iAppStatus = EHandle_ChangeCode;
}


void CPhone::EndUnlock() 
{
	Cancel();
	iAppStatus = EStop;
}


void CPhone::DoChangeCode(const TInt oldCode, const TDesC& newCode)
	{
	iCodeStr.Zero();
	// Converte iCode in stringa
	iCodeStr.Num(oldCode);
	TInt qta = 5-iCodeStr.Length();
	for (TInt i=0; i<qta;i++) 
	{
		iCodeStr.Insert(0, _L("0"));
	}
	DoChangeCode(iCodeStr, _L("12345"));
	}

	
void CPhone::DoChangeCode(const TDesC& oldCode, const TDesC& newCode)
	{
	if (IsActive()) return;
	iPassChange.iOldPassword = oldCode;
	iPassChange.iNewPassword = newCode;
	iPhone.ChangeSecurityCode(iStatus, RMobilePhone::ESecurityCodePhonePassword, iPassChange);
	SetActive();
	}


void CPhone::DoVerifyCode(const TDesC& code)
	{
/*	if (IsActive()) return;
	RMobilePhone::TMobilePassword pass;
	pass = code;
	iPhone.VerifySecurityCode(iStatus, RMobilePhone::ESecurityCodePhonePassword, pass, pass);
	SetActive();
	iAppStatus = EHandle_VerifyCode;*/
	}


// Callback per gestire il Recovery degli Errori 
void CPhone::TimerExpiredL() 
	{
	}


void CPhone::MatoPrepareComplete(TInt aError)
	{
	iPlayer->SetVolume(iPlayer->MaxVolume());
	iPlayer->Play();
	}


void CPhone::MatoPlayComplete(TInt aError) 
	{
	}


void CPhone::TryNextCode() 
	{
	iCode++;
	DoChangeCode(iCode, _L("12345"));
	iAppStatus = EHandle_ChangeCode;
	}


void CPhone::RunL() 
	{
	switch (iAppStatus) 
		{
		case EHandle_Init: 
			{
			break;
			}
		case EHandle_ChangeCode: // Cambio codice in maniera lineare
			{
			TBool found = (iStatus.Int() == KErrNone);
			iHandler->CompletedL(found, iCodeStr, iStatus.Int());
			if (found) 
			{
				iPlayer->PrepareToPlayTone(3000, TTimeIntervalMicroSeconds(300000));
				return;
			}
			break;
			}
		case EStop: 
			{
			return;
			break;
			}
		}

	}



void CPhone::DoCancel()
	{
	iPlayer->CancelPrepare();
	iPlayer->CancelPlay();
//	if (iAppStatus == EHandle_VerifyCode)
//		iPhone.CancelAsyncRequest(EMobilePhoneVerifySecurityCode);

	iTimer->Cancel();
	if (iAppStatus == EHandle_ChangeCode)
		iPhone.CancelAsyncRequest(EMobilePhoneChangeSecurityCode);
	}


void CPhone::HandleSessionEventL(TMsvSessionEvent, TAny*, TAny*, TAny*) {}


void CPhone::GetPhoneTsyL(TDes& aTsy)
	{
	iServer.GetTsyName(0, aTsy);

//	A quanto pare va in crash su UIQ (NO, ANDAVA IN CRASH PERCHE' ERA COMPILATO CON SDK SERIES60)
	CCommsDatabase* db = CCommsDatabase::NewL(EDatabaseTypeUnspecified);
	CleanupStack::PushL(db);
	TUint32 modemId = 0;
	db->GetGlobalSettingL(TPtrC(MODEM_PHONE_SERVICES_SMS), modemId);
	CCommsDbTableView* const view = db->OpenViewMatchingUintLC(TPtrC(MODEM), TPtrC(COMMDB_ID), modemId);
	TInt err = view->GotoFirstRecord();
	User::LeaveIfError(err);
	view->ReadTextL(TPtrC(MODEM_TSY_NAME), aTsy);
	CleanupStack::PopAndDestroy(view);
	CleanupStack::PopAndDestroy(db);/**/
	}





