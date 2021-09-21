

// INCLUDE FILES
#include <e32std.h>
#include <avkon.hrh>
#include <aknnavi.h>
#include <akntitle.h> 
#include <eikapp.h>		// Application
#include <AknQueryDialog.h> 
#include <AknNoteWrappers.h> 
#include <cntdb.h>
#include <bautils.h>

#include "base64.h"
#include "UnlockMe.rsg"
#include "UnlockMe.hrh"
#include "UnlockMe.pan"
#include "UnlockMeAppUi.h"
#include "CreditsView.h"
#include "SplashView.h"
#include "AboutView.h"



#define InfoMsg(R_RSC)  {CAknInformationNote* dialog = new ( ELeave ) CAknInformationNote(ETrue); \
						TBuf<64> aDes; \
    					iCoeEnv->ReadResource( aDes, R_RSC ); \
						dialog->ExecuteLD( aDes );}

#define ErrorMsg(R_RSC) {CAknErrorNote* dialog = new ( ELeave ) CAknErrorNote(ETrue); \
						TBuf<64> aDes; \
						iCoeEnv->ReadResource( aDes, R_RSC ); \
						dialog->ExecuteLD( aDes );}

#define WarnMsg(R_RSC)  {CAknWarningNote* dialog = new ( ELeave ) CAknWarningNote(ETrue); \
						TBuf<64> aDes; \
    					iCoeEnv->ReadResource( aDes, R_RSC ); \
						dialog->ExecuteLD( aDes );}





// ========================= MEMBER FUNCTIONS ==================================
// -----------------------------------------------------------------------------
// CUnlockMeAppUi::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CUnlockMeAppUi::ConstructL()
    {
	BaseConstructL(EAknEnableSkin);

	CSplashView* iAppView1 = CSplashView::NewLC(*this);
    AddViewL( iAppView1 );
	CleanupStack::Pop();/**/
	//TimerExpiredL();
	}



void CUnlockMeAppUi::TimerExpiredL() 
{
	// Show tabs for main views from resources
    CEikStatusPane *sp = StatusPane();

    CAknTabGroup* tabGroup = NULL;
    // Fetch pointer to the default navi pane control
    CAknNavigationControlContainer* iNaviPane = static_cast<CAknNavigationControlContainer*> 
		( sp->ControlL( TUid::Uid( EEikStatusPaneUidNavi )  ) );/**/
	
    iDecoratedTabGroup = iNaviPane->ResourceDecorator();
    if ( iDecoratedTabGroup )
    {
        tabGroup = static_cast<CAknTabGroup*> 
			( iDecoratedTabGroup->DecoratedControl() );
    }/**/

	CCreditsView* iCreditsView1 = CCreditsView::NewLC();
	AddViewL( iCreditsView1 );
	CleanupStack::Pop();

	CAboutView* iAppView1 = CAboutView::NewLC();
    AddViewL( iAppView1 );
	CleanupStack::Pop();
	
    SetDefaultViewL( *iAppView1 );
    if (  tabGroup  )
	{
        ActivateLocalViewL(  TUid::Uid(  tabGroup->ActiveTabId()  )  );
	}
    else  // just in case
	{
        ActivateLocalViewL(  iAppView1->Id()  );
	}
}



// -----------------------------------------------------------------------------
// CAknExPopListAppUi::DynInitMenuPaneL()
// This function is called by the EIKON framework just before it displays
// a menu pane. Its default implementation is empty, and by overriding it,
// the application can set the state of menu items dynamically according
// to the state of application data.
// -----------------------------------------------------------------------------
//
void CUnlockMeAppUi::DynInitMenuPaneL( TInt /*aResourceId*/,
										  CEikMenuPane* /*aMenuPane*/ )
	{
    // No implementation required
	}


// Per la corretta gestione dei Tab e delle relative viste
TKeyResponse CUnlockMeAppUi::HandleKeyEventL( const TKeyEvent& aKeyEvent,
												 TEventCode /*aType*/ )
	{
//	if (iDecoratedTabGroup == NULL) return EKeyWasNotConsumed;

    return EKeyWasConsumed;
    }


// -----------------------------------------------------------------------------
// CUnlockMeAppUi::HandleCommandL()
// Takes care of command handling.
// -----------------------------------------------------------------------------
//
void CUnlockMeAppUi::HandleCommandL( TInt aCommand )
    {
    switch ( aCommand )
        {
		case ECredits:
			{
	        ActivateLocalViewL( KViewCreditsId );
			break;
			}
        case EAknSoftkeyBack:
			{
	        ActivateLocalViewL( KViewAboutId );
			break;
			}
        case EEikCmdExit:
        case EAknSoftkeyExit:
			{
			CAknQueryDialog* dlg = CAknQueryDialog::NewL();
			if ( dlg->ExecuteLD(R_REALLY_EXIT) )
				{
				Exit();
				}				
            break;
			}
        default:
//            Panic( EUnlockMeBasicUi );
            break;
        }
    }


CUnlockMeAppUi::~CUnlockMeAppUi() 
	{
	if (iDecoratedTabGroup)
		delete iDecoratedTabGroup;
/*	this->RemoveView(KViewCreditsId);
	this->RemoveView(KViewAboutId);
	this->RemoveView(KView0Id);

	//if (tabGroup)
	//	delete tabGroup;/**/
	}

// End of File
