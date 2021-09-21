

// INCLUDE FILES
#include <aknviewappui.h>
#include <aknconsts.h>

#include "SplashView.h"
#include "SplashContainer.h"
#include "unlockme.hrh"
#include <eikmenup.h>
#include <akntitle.h> 
#include <aknquerydialog.h> 
// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CSplashView::CSplashView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSplashView::CSplashView()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CSplashView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSplashView* CSplashView::NewL(MTimeOutNotifier& notif)
    {
    CSplashView* self = CSplashView::NewLC(notif);
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CSplashView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSplashView* CSplashView::NewLC(MTimeOutNotifier& notif)
    {
    CSplashView* self = new ( ELeave ) CSplashView();
    CleanupStack::PushL( self );
    self->ConstructL(notif);
    return self;
    }

// -----------------------------------------------------------------------------
// CSplashView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSplashView::ConstructL(MTimeOutNotifier& notif)
    {
   // BaseConstructL( R_unlockme_VIEW1 );
	notifier = &notif;
    }

// -----------------------------------------------------------------------------
// CSplashView::~CSplashView()
// Destructor.
// -----------------------------------------------------------------------------
//
CSplashView::~CSplashView()
    {
    if ( iContainer )
	{
        AppUi()->RemoveFromStack( iContainer );
	}
    delete iContainer;
    }

// -----------------------------------------------------------------------------
// CSplashView::Id()
// Returns View's ID.
// -----------------------------------------------------------------------------
//
TUid CSplashView::Id() const
    {
    return KView0Id;
    }

// -----------------------------------------------------------------------------
// CSplashView::DoActivateL()
// Activate an unlockme1
// -----------------------------------------------------------------------------
//
void CSplashView::DoActivateL( const TVwsViewId& /*aPrevViewId*/,
                                    TUid /*aCustomMessageId*/,
                                    const TDesC8& /*aCustomMessage*/)
    {
	iContainer = new ( ELeave ) CSplashContainer();
	iContainer->SetMopParent(this);
    iContainer->ConstructL( iAvkonViewAppUi->ApplicationRect() );
    AppUi()->AddToStackL( iContainer );

#ifdef __WINS__
	TTimeIntervalMicroSeconds32 timeout(1000000);
#else
	TTimeIntervalMicroSeconds32 timeout(3000000);
#endif
	
    iTimer = CTimeOutTimer::NewL( EPriorityHigh, *notifier );
	iTimer->After(timeout);
    }

// -----------------------------------------------------------------------------
// CSplashView::DoDeactivate()
// DeActivate an unlockme1
// -----------------------------------------------------------------------------
//
void CSplashView::DoDeactivate()
    {

    if ( iContainer )
        {
        // Remove View1's container form controllStack
        AppUi()->RemoveFromStack( iContainer );
        delete iContainer;
        iContainer = NULL;
        }

	if (iTimer) 
		{
		delete iTimer;
		iTimer = NULL;
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
void CSplashView::DynInitMenuPaneL( TInt aResourceId,
										CEikMenuPane* aMenuPane )
	{
	}
// -----------------------------------------------------------------------------
// CSplashView::HandleCommandL()
// Takes care of Command handling.
// -----------------------------------------------------------------------------
//
void CSplashView::HandleCommandL( TInt aCommand )
    {
	switch (aCommand)
        {
		default:
			{
			//AppUi()->HandleCommandL( aCommand );
			}
        }
    }


// -----------------------------------------------------------------------------
// CAknExPopListView2::HandleClientRectChange()
// Handles Clients Rect
// -----------------------------------------------------------------------------
//
void CSplashView::HandleClientRectChange()
	{	
/*    if ( iContainer )
		{
        iContainer->SetRect( ClientRect() );
		}*/
	}
