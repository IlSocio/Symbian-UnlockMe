

// INCLUDE FILES
#include <aknviewappui.h>
#include <aknconsts.h>
#include <unlockme.rsg>

#include "CreditsView.h"
#include "CreditsContainer.h"
#include "unlockme.hrh"
#include <eikmenup.h>
#include <akntitle.h> 
#include <aknquerydialog.h> 
// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CCreditsView::CCreditsView()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CCreditsView::CCreditsView()
    {
    // No implementation required
    }


// -----------------------------------------------------------------------------
// CCreditsView::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CCreditsView* CCreditsView::NewL()
    {
    CCreditsView* self = CCreditsView::NewLC();
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CCreditsView::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CCreditsView* CCreditsView::NewLC()
    {
    CCreditsView* self = new ( ELeave ) CCreditsView();
    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CCreditsView::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CCreditsView::ConstructL()
    {
    BaseConstructL( R_UNLOCKME_VIEW_CREDITS );
    }

// -----------------------------------------------------------------------------
// CCreditsView::~CCreditsView()
// Destructor.
// -----------------------------------------------------------------------------
//
CCreditsView::~CCreditsView()
    {
    if ( iContainer )
	{
        AppUi()->RemoveFromStack( iContainer );
	}
    delete iContainer;
    }

// -----------------------------------------------------------------------------
// CCreditsView::Id()
// Returns View's ID.
// -----------------------------------------------------------------------------
//
TUid CCreditsView::Id() const
    {
    return KViewCreditsId;
    }

// -----------------------------------------------------------------------------
// CCreditsView::DoActivateL()
// Activate an unlockme1
// -----------------------------------------------------------------------------
//
void CCreditsView::DoActivateL( const TVwsViewId& /*aPrevViewId*/,
                                    TUid /*aCustomMessageId*/,
                                    const TDesC8& /*aCustomMessage*/)
    {
	iContainer = new ( ELeave ) CCreditsContainer();
	iContainer->SetMopParent(this);
    iContainer->ConstructL( ClientRect() );
    AppUi()->AddToStackL( iContainer );
    }

// -----------------------------------------------------------------------------
// CCreditsView::DoDeactivate()
// DeActivate an unlockme1
// -----------------------------------------------------------------------------
//
void CCreditsView::DoDeactivate()
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
void CCreditsView::DynInitMenuPaneL( TInt aResourceId,
										CEikMenuPane* aMenuPane )
	{
	}
// -----------------------------------------------------------------------------
// CCreditsView::HandleCommandL()
// Takes care of Command handling.
// -----------------------------------------------------------------------------
//
void CCreditsView::HandleCommandL( TInt aCommand )
    {
	switch (aCommand)
        {
		case EAknSoftkeyBack:
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
void CCreditsView::HandleClientRectChange()
	{	
    if ( iContainer )
		{
        iContainer->SetRect( ClientRect() );
		}
	}
