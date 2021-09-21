


#ifndef __ABOUT_VIEW_H__
#define __ABOUT_VIEW_H__

// INCLUDES
#include <aknview.h>
#include "Phone.h"

// FORWARD DECLARATIONS
class CAboutContainer;
const TUid KViewAboutId = { 1 };

// CLASS DECLARATION

/**
* CAboutView view class.
* An instance of the Application View object for the 
* example application
*/
class CAboutView: public CAknView, public MLockHandler, public MTimeOutNotifier
    {
    public:   // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Construct a CAboutView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CAboutView
        */
        static CAboutView* NewL();


        /**
        * NewLC.
        * Two-phased constructor.
        * Construct a CAboutView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CAboutView
        */
        static CAboutView* NewLC();

        void TimerExpiredL();
		
		void CompletedL(TBool found, const TDesC& code, const TInt error);

        /**
        * ~CAboutView.
        * Virtual Destructor.
        */
        virtual ~CAboutView();


    public: // Functions from base classes from CAknView


        /**
        * Id
        * @return Id Uid value
        */
        TUid Id() const;


        /**
        * HandleCommandL
        * From CAknView, takes care of command handling.
        * @param aCommand Command to be handled
        */
        void HandleCommandL( TInt aCommand );

        /**
        * HandleClientRectChange
        * From CAknView, handles client rectangle is changed.
        */
        void HandleClientRectChange();

        /**
        * DoActivateL
        * From CAknExView, activate an AknView.
        * @param aPrevViewId The id of the previous view
        * @param aCustomMessageId message identifier
        * @param aCustomMessage custom message provided when the view is changed
        */
        void DoActivateL( const TVwsViewId& aPrevViewId,
                          TUid aCustomMessageId,
                          const TDesC8& aCustomMessage );

        /**
        * DoDeactivate
        * From AknView, deactivate an AknView
        * Remove the container class instance from the App UI's stack and
        * deletes the instance
        */
        void DoDeactivate();

    private:   // Constructors and destructor

		/** 
		* From MEikMenuObserver
		* @param aResourceId menu pane resource ID
		* @param aMenuPane menu pane pointer
        */
        void DynInitMenuPaneL( TInt aResourceId,
			CEikMenuPane* aMenuPane );

        /**
        * CAboutView.
        * C++ default constructor.
        */
        CAboutView();


        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    private: // Data
		CTimeOutTimer* iTimer;
		TInt i;
		CPhone* iPhone;
        /**
        * iContainer,container for this view
        * owned by CAboutView object.
        */
        CAboutContainer* iContainer;

        /** View Identifier **/
        TUid iIdentifier;
    };


#endif // ___VIEW1_H__


// End of File