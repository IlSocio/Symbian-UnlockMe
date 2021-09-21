

#ifndef __UnlockMe_DOCUMENT_H__
#define __UnlockMe_DOCUMENT_H__



// INCLUDES
#include <akndoc.h>


// FORWARD DECLARATIONS
class CUnlockMeAppUi;
class CEikApplication;



// CLASS DECLARATION

/**
* CUnlockMeDocument application class.
* An instance of class CUnlockMeDocument is the Document part of the AVKON
* application framework for the CUnlockMeApplication example application.
*/
class CUnlockMeDocument : public CAknDocument
    {
    public:  // Constructors and destructor


        /**
        * NewL.
        * Two-phased constructor.
        * Construct a CUnlockMeDocument for the AVKON application aApp.
        * Using two phase construction, and return a pointer to the created object.
        * @param aApp Application creating this document.
        * @return A pointer to the created instance of CUnlockMeDocument.
        */
        static CUnlockMeDocument* NewL( CEikApplication& aApp );

        /**
        * NewLC.
        * Two-phased constructor.
        * Construct a CUnlockMeDocument for the AVKON application aApp.
        * Using two phase construction, and return a pointer to the created object.
        * @param aApp Application creating this document.
        * @return A pointer to the created instance of CUnlockMeDocument.
        */
        static CUnlockMeDocument* NewLC( CEikApplication& aApp );

        /**
        * ~CUnlockMeDocument
        * Virtual Destructor.
        */
        virtual ~CUnlockMeDocument();


    public: // from CAknDocument

        /**
        * CreateAppUiL
        * From CEikDocument, CreateAppUiL.
        * Create a CUnlockMeAppUi object and return a pointer to it.
        * The object returned is owned by the Uikon framework.
        * @return Pointer to created instance of AppUi.
        */
        CEikAppUi* CreateAppUiL();

    private:  // Constructors

        /**
        * ConstructL
        * 2nd phase constructor.
        */
        void ConstructL();

        /**
        * CUnlockMeDocument.
        * C++ default constructor.
        * @param aApp Reference to Application class object
        */
        CUnlockMeDocument( CEikApplication& aApp );

    };


#endif // __UnlockMe_DOCUMENT_H__


// End of File