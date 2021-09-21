

// INCLUDE FILES
#include "unlockmeApplication.h"
//#include <avkon.mbg>


// ========================== OTHER EXPORTED FUNCTIONS =========================

// -----------------------------------------------------------------------------
// E32Dll()
// Entry point function for Symbian Apps.
// -----------------------------------------------------------------------------
//
GLDEF_C TInt E32Dll( TDllReason /*aReason*/ )
    {
    return KErrNone;
    }

// -----------------------------------------------------------------------------
// NewApplication()
// Constructs CAknExMenuApp.
// Create an application, and return a pointer to it
// -----------------------------------------------------------------------------
EXPORT_C CApaApplication* NewApplication()
    {
    return ( static_cast<CApaApplication*> ( new CUnlockMeApplication ) );
    }

// End of File
