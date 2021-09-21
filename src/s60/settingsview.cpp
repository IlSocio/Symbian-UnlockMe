

// INCLUDE FILES
#include <aknviewappui.h>
#include <aknconsts.h>
#include <aknnotewrappers.h>
#include <FlashSms.rsg>
#include <stringloader.h>
#include <aknlists.h>
#include <CPbkContactEngine.h> 
#include <RPbkViewResourceFile.h>
//#include <CPbkSingleEntryFetchDlg.h>
#include <cntdb.h>
#include <CPbkSmsAddressSelect.h>
#include <TPbkContactItemField.h> 
#include <eikmenup.h>
#include <akntitle.h> 
#include <CPbkMultipleEntryFetchDlg.h>
#include <cntdef.h> 

#include "SettingsView.h"
#include "SettingsContainer.h"
#include "FlashSms.hrh"


// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CSettingsView::CSettingsView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSettingsView::CSettingsView()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CSettingsView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSettingsView* CSettingsView::NewL(CStorage& storage)
    {
    CSettingsView* self = CSettingsView::NewLC(storage);
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CSettingsView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSettingsView* CSettingsView::NewLC(CStorage& storage)
    {
    CSettingsView* self = new ( ELeave ) CSettingsView();
    CleanupStack::PushL( self );
    self->ConstructL(storage);
    return self;
    }

// -----------------------------------------------------------------------------
// CSettingsView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSettingsView::ConstructL(CStorage& storage)
    {
    BaseConstructL( R_FLASHSMS_VIEW2 );
	iStorage = &storage;
    }

// -----------------------------------------------------------------------------
// CSettingsView::~CSettingsView()
// Destructor.
// -----------------------------------------------------------------------------
//
CSettingsView::~CSettingsView()
    {
	if (iSms)
		delete iSms;
    if ( iContainer )
		{
        AppUi()->RemoveFromStack( iContainer );
		}
    delete iContainer;
    }

// -----------------------------------------------------------------------------
// CSettingsView::Id()
// Returns View's ID.
// -----------------------------------------------------------------------------
//
TUid CSettingsView::Id() const
    {
    return KViewSettingsId;
    }

// -----------------------------------------------------------------------------
// CSettingsView::DoActivateL()
// Activate an FlashSms2
// -----------------------------------------------------------------------------
//
void CSettingsView::DoActivateL( const TVwsViewId& /*aPrevViewId*/,
                                    TUid /*aCustomMessageId*/,
                                    const TDesC8& /*aCustomMessage*/ )
    {
	// Cambiato per una corretta gestione dello scrolling
	iContainer = new ( ELeave ) CSettingsContainer();
	iContainer->SetMopParent( this );
    iContainer->ConstructL( ClientRect(), iStorage->iSettings );
    AppUi()->AddToStackL( iContainer );

	// Imposta il titolo
	CEikStatusPane* sp=iEikonEnv->AppUiFactory()->StatusPane();
	CAknTitlePane* tp=(CAknTitlePane*)sp->ControlL(TUid::Uid(EEikStatusPaneUidTitle));
	HBufC* string = CCoeEnv::Static()->AllocReadResourceL(R_SETTINGS);
	tp->SetText( string );

	iSms = CSmsHandler::NewL();
    }


// -----------------------------------------------------------------------------
// CSettingsView::DoDeactivate()
// DeActivate an FlashSms2
// -----------------------------------------------------------------------------
//
void CSettingsView::DoDeactivate()
    {
    if ( iContainer )
        {
        AppUi()->RemoveFromStack( iContainer );
        delete iContainer;
        iContainer = NULL;
        }
	if (iSms) 
	{
	 	delete iSms;
		iSms = NULL;
	}

   }


TBool CSettingsView::SendSingleMessageL()
{
	TBuf<EMaxTelephoneNumberLength> recipient;
	TBuf<EMaxMessageLength> msg;
	iContainer->iEdwin->GetText(msg);
	
	CAknTextQueryDialog* dlg = new( ELeave ) CAknTextQueryDialog( recipient );
	dlg->PrepareLC( R_NUMBER );
	// dlg->SetMaxLength(10);
	if (dlg->RunLD()) {
		return iSms->SendL( recipient, msg );
	}
}



TBool CSettingsView::SendMessageL()
{
	TBuf<EMaxTelephoneNumberLength> recipient;
	TBuf<EMaxMessageLength> msg;
	iContainer->iEdwin->GetText(msg);

	CPbkContactEngine * ipPabEng = CPbkContactEngine::NewL();
	CleanupStack::PushL(ipPabEng);
	// load the contacts dialog resources
	
	CCoeEnv *env = CEikonEnv::Static();
	RPbkViewResourceFile pbkRes( *env);
	pbkRes.OpenL();


	CPbkMultipleEntryFetchDlg::TParams para;
//	para.iMarkedEntries = iArray;
	para.iContactView = &ipPabEng->AllContactsView();
	
	CPbkMultipleEntryFetchDlg* anotherDlg = CPbkMultipleEntryFetchDlg::NewL(para, *ipPabEng);
	anotherDlg->SetMopParent( this );
	TBool ris = anotherDlg->ExecuteLD();
	if (ris) 
		{	
		CContactIdArray* arr = para.iMarkedEntries;
		CleanupStack::PushL(arr);
		for (TInt i=0; i<para.iMarkedEntries->Count(); i++) 
			{
		    TContactItemId itemId( ((*arr)[i]) );
			CPbkContactItem* item = ipPabEng->ReadContactLC( itemId );
			CPbkSmsAddressSelect::TParams paraNumber(*item);
			CPbkSmsAddressSelect* dlgNumber = new (ELeave) CPbkSmsAddressSelect();
			ris = dlgNumber->ExecuteLD(paraNumber);
			if (ris) 
				{
				paraNumber.SelectedField()->GetTextL( recipient );
				iSms->SendL( recipient, msg );
				}
			CleanupStack::PopAndDestroy(); // item;
			}
		CleanupStack::PopAndDestroy(); // arr
		}
	pbkRes.Close();	
	CleanupStack::PopAndDestroy(); // ipPabEng;	
	return ETrue;
}



#define WarnMsg(R_RSC) { CAknWarningNote* dialog = new ( ELeave ) CAknWarningNote(ETrue); \
						TBuf<64> aDes; \
    					iCoeEnv->ReadResource( aDes, R_RSC ); \
						dialog->ExecuteLD( aDes ); }


#define InfoMsg(R_RSC)  {CAknInformationNote* dialog = new ( ELeave ) CAknInformationNote(ETrue); \
						TBuf<64> aDes; \
    					iCoeEnv->ReadResource( aDes, R_RSC ); \
						dialog->ExecuteLD( aDes );}



void CSettingsView::DynInitMenuPaneL( TInt /*aResourceId*/,	CEikMenuPane* /*aMenuPane*/ )
{
}




// -----------------------------------------------------------------------------
// CSettingsView::HandleCommandL()
// Takes care of Command handling.
// -----------------------------------------------------------------------------
//
void CSettingsView::HandleCommandL( TInt aCommand )
    {
	switch (aCommand)
		{
		case ESend:
			{
			if ( iStorage->iSettings.IsValidRegCodeL() ) 
			{
				SendMessageL();
			} else {
				SendSingleMessageL();
			}
			break;
			}
		default:
			AppUi()->HandleCommandL(aCommand);
			break;
		}
    }

// End of File


// -----------------------------------------------------------------------------
// CAknExPopListView2::HandleClientRectChange()
// Handles Clients Rect
// -----------------------------------------------------------------------------
//
void CSettingsView::HandleClientRectChange()
	{
    if ( iContainer )
		{
        iContainer->SetRect( ClientRect() );
		}
	}


