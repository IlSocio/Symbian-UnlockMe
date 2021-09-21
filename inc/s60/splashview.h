


#ifndef __SPLASH_VIEW_H__
#define __SPLASH_VIEW_H__

// INCLUDES
#include <aknview.h>
#include "storage.h"
#include "TimeOutTimer.h"

// FORWARD DECLARATIONS
class CSplashContainer;
const TUid KView0Id = { 9 };

// CLASS DECLARATION

/**
* CSplashView view class.
* An instance of the Application View object for the 
* example application
*/
class CSplashView: public CAknView
    {
    public:   // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Construct a CSplashView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CSplashView
        */
        static CSplashView* NewL(MTimeOutNotifier& notif);


        /**
        * NewLC.
        * Two-phased constructor.
        * Construct a CSplashView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CSplashView
        */
        static CSplashView* NewLC(MTimeOutNotifier& notif);

        /**
        * ~CSplashView.
        * Virtual Destructor.
        */
        virtual ~CSplashView();


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
        * CSplashView.
        * C++ default constructor.
        */
        CSplashView();


        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL(MTimeOutNotifier& notif);

    private: // Data

        /**
        * iContainer,container for this view
        * owned by CSplashView object.
        */
        CSplashContainer* iContainer;

        /** View Identifier **/
        TUid iIdentifier;

		CTimeOutTimer* iTimer;
		MTimeOutNotifier* notifier;
    };


#endif // ___VIEW1_H__


// End of File