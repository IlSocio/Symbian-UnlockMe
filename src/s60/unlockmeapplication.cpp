

// INCLUDE FILES
#include "UnlockMeDocument.h"
#include "UnlockMeApplication.h"


// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CUnlockMeApplication::CreateDocumentL()
// Create an UnlockMe document, and return a pointer to it
// -----------------------------------------------------------------------------
//
CApaDocument* CUnlockMeApplication::CreateDocumentL()
    {
    return( static_cast< CApaDocument* >( CUnlockMeDocument::NewL( *this ) ) );
    }

// -----------------------------------------------------------------------------
// CUnlockMeApplication::AppDllUid()
// Returns application UID
// -----------------------------------------------------------------------------
//
TUid CUnlockMeApplication::AppDllUid() const
    {
    return KUidUnlockMeApp;
    }

// End of File