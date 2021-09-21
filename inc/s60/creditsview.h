/* Copyright (c) 2004, Nokia. All rights reserved */



#ifndef __CREDITS_VIEW_H__
#define __CREDITS_VIEW_H__

// INCLUDES
#include <aknview.h>
#include "storage.h"
#include "TimeOutTimer.h"

// FORWARD DECLARATIONS
class CCreditsContainer;
const TUid KViewCreditsId = { 10 };

// CLASS DECLARATION

/**
* CCreditsView view class.
* An instance of the Application View object for the 
* example application
*/
class CCreditsView: public CAknView
    {
    public:   // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * Construct a CCreditsView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CCreditsView
        */
        static CCreditsView* NewL();


        /**
        * NewLC.
        * Two-phased constructor.
        * Construct a CCreditsView for the AVKON application aApp.
        * Using two phase construction,and return a pointer to the created object
        * @return a pointer to the created instance of CCreditsView
        */
        static CCreditsView* NewLC();

        /**
        * ~CCreditsView.
        * Virtual Destructor.
        */
        virtual ~CCreditsView();


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
        * CCreditsView.
        * C++ default constructor.
        */
        CCreditsView();


        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    private: // Data

        /**
        * iContainer,container for this view
        * owned by CCreditsView object.
        */
        CCreditsContainer* iContainer;

        /** View Identifier **/
        TUid iIdentifier;

		CTimeOutTimer* iTimer;
		MTimeOutNotifier* notifier;
    };


#endif // ___VIEW1_H__


// End of File