

#ifndef __UnlockMe_APPLICATION_H__
#define __UnlockMe_APPLICATION_H__


// INCLUDES
#include <aknapp.h>


// CONSTANTS
// Uid for the application, should match the one in the mmp file
const TUid KUidUnlockMeApp = { 0x1020DC98 };


// CLASS DECLARATION

/**
* An instance of CUnlockMeApplication is the application part of the AVKON
* application framework for the UnlockMe example application
*/
class CUnlockMeApplication : public CAknApplication
    {

    public:  // from CAknApplication

        /**
        * AppDllUid
        * @return returns application's UID (KUidAknExMenu).
        */
        TUid AppDllUid() const;


    protected: // from CAknApplication


        /**
        * CreateDocumentL
        * Creates CUnlockMeDocument document object.
        * The returned pointer in not owned by the CUnlockMeApplication object.
        * @return A pointer to the created document object.
        */
        CApaDocument* CreateDocumentL();
    };

#endif // __UnlockMe_APPLICATION_H__

// End of File
