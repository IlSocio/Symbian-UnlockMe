

// INCLUDE FILES
#include "UnlockMeAppUi.h"
#include "UnlockMeDocument.h"


// ========================= MEMBER FUNCTIONS ==================================


// -----------------------------------------------------------------------------
// CUnlockMeDocument::CUnlockMeDocument()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CUnlockMeDocument::CUnlockMeDocument( CEikApplication& aApp ) :
                                          CAknDocument( aApp )
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CUnlockMeDocument::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CUnlockMeDocument* CUnlockMeDocument::NewL( CEikApplication& aApp )
    {
    CUnlockMeDocument* self = NewLC( aApp );
    CleanupStack::Pop( self );
    return self;
    }


// -----------------------------------------------------------------------------
// CUnlockMeDocument::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CUnlockMeDocument* CUnlockMeDocument::NewLC( CEikApplication& aApp )
    {
    CUnlockMeDocument* self = new ( ELeave ) CUnlockMeDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CUnlockMeDocument::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CUnlockMeDocument::ConstructL()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CUnlockMeDocument::~CUnlockMeDocument()
// Destructor.
// -----------------------------------------------------------------------------
//
CUnlockMeDocument::~CUnlockMeDocument()
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CUnlockMeDocument::CreateAppUiL()
// Create the application user interface, and return a pointer to it
// -----------------------------------------------------------------------------
//
CEikAppUi* CUnlockMeDocument::CreateAppUiL()
    {
    return( static_cast<CEikAppUi*>( new ( ELeave ) CUnlockMeAppUi ) );
    }

// End of File
