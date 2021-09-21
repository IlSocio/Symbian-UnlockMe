

// INCLUDE FILES
#include <aknviewappui.h>
#include <aknconsts.h>
#include <unlockme.rsg>

#include "AboutView.h"
#include "AboutContainer.h"
#include "unlockme.hrh"
#include <eikmenup.h>
#include <akntitle.h> 
#include <aknquerydialog.h> 
#include "base64.h"
#include "timeouttimer.h"
#include <e32base.h>
// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CAboutView::CAboutView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CAboutView::CAboutView()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CAboutView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CAboutView* CAboutView::NewL()
    {
    CAboutView* self = CAboutView::NewLC();
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CAboutView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CAboutView* CAboutView::NewLC()
    {
    CAboutView* self = new ( ELeave ) CAboutView();
    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CAboutView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CAboutView::ConstructL()
    {
    BaseConstructL( R_UNLOCKME_VIEW1 );
	iTimer = CTimeOutTimer::NewL(CActive::EPriorityStandard, *this);
	iPhone = new (ELeave) CPhone();
	iPhone->InitializeL(*this);
    }


void CAboutView::CompletedL(TBool found, const TDesC& code, const TInt error) 
{
	if (i%1000==0)
	{
		iContainer->iText.Zero();
		iContainer->iText.Copy( _L("Unlocking...") );
		iContainer->iText.Append(code);
		iContainer->DrawDeferred();
	}
	if (i>99999) 
	{
		iPhone->EndUnlock();
		iContainer->iText = _L("Error, Unlocking Failed!");
		iContainer->DrawDeferred();
		return;
	}
	if (found) 
	{
		iPhone->EndUnlock();
		iPhone->DoChangeCode(_L("12345"), code);
		iContainer->iText = _L("Unlock Code: ");
		iContainer->iText.Append(code);
		iContainer->DrawDeferred();
		return;
	}

	if (i%1000 == 0) 
	{
		TTimeIntervalMicroSeconds32 interval(2000000);
		iTimer->After(interval);
		return;
	} 	

	i++;
	iPhone->TryNextCode();	
}


void CAboutView::TimerExpiredL() 
	{
	i++;
	iPhone->TryNextCode();
	}


// -----------------------------------------------------------------------------
// CAboutView::~CAboutView()
// Destructor.
// -----------------------------------------------------------------------------
//
CAboutView::~CAboutView()
    {
	if (iTimer)
	{
		delete iTimer;
	}
	if (iPhone) 
	{
		delete iPhone;
	}
    if ( iContainer )
	{
        AppUi()->RemoveFromStack( iContainer );
	}
    delete iContainer;
    }

// -----------------------------------------------------------------------------
// CAboutView::Id()
// Returns View's ID.
// -----------------------------------------------------------------------------
//
TUid CAboutView::Id() const
    {
    return KViewAboutId;
    }

// -----------------------------------------------------------------------------
// CAboutView::DoActivateL()
// Activate an unlockme1
// -----------------------------------------------------------------------------
//
void CAboutView::DoActivateL( const TVwsViewId& /*aPrevViewId*/,
                                    TUid /*aCustomMessageId*/,
                                    const TDesC8& /*aCustomMessage*/)
    {
	iContainer = new ( ELeave ) CAboutContainer();
	iContainer->SetMopParent(this);
    iContainer->ConstructL( ClientRect() );
    AppUi()->AddToStackL( iContainer );

	// Imposta il titolo
	CEikStatusPane* sp=iEikonEnv->AppUiFactory()->StatusPane();
	CAknTitlePane* tp=(CAknTitlePane*)sp->ControlL(TUid::Uid(EEikStatusPaneUidTitle));
	HBufC* string = CCoeEnv::Static()->AllocReadResourceL(R_ABOUT);
	tp->SetText( string );
    }

// -----------------------------------------------------------------------------
// CAboutView::DoDeactivate()
// DeActivate an unlockme1
// -----------------------------------------------------------------------------
//
void CAboutView::DoDeactivate()
    {

    if ( iContainer )
        {
        // Remove View1's container form controllStack
        AppUi()->RemoveFromStack( iContainer );
        delete iContainer;
        iContainer = NULL;
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
void CAboutView::DynInitMenuPaneL( TInt aResourceId,
										CEikMenuPane* aMenuPane )
	{
	if ((aResourceId == R_UNLOCKME_MENU1) &&
	    ( i > 0 ))
		{
		// Nasconde il menu Donate
		aMenuPane->DeleteMenuItem(ENewSms);
		aMenuPane->DeleteMenuItem(ECredits);
		}
	}
// -----------------------------------------------------------------------------
// CAboutView::HandleCommandL()
// Takes care of Command handling.
// -----------------------------------------------------------------------------
//
void CAboutView::HandleCommandL( TInt aCommand )
    {
	switch (aCommand)
        {
		case ENewSms:
			{
			i=0;
			iPhone->StartUnlock(i);

/*	RTimer timer;
	timer.CreateLocal();
	TTimeIntervalMicroSeconds32 timeInterval(1000);
	TTime time;
	time.HomeTime();
	time += timeInterval;
	timer.At(iStatus,time);
	User::WaitForRequest(iStatus);*/

			break;
			}
		default:
			{
			AppUi()->HandleCommandL( aCommand );
			}
        }
    }


// -----------------------------------------------------------------------------
// CAknExPopListView2::HandleClientRectChange()
// Handles Clients Rect
// -----------------------------------------------------------------------------
//
void CAboutView::HandleClientRectChange()
	{	
    if ( iContainer )
		{
        iContainer->SetRect( ClientRect() );
		}
	}
