

#ifndef __UnlockMe_APPUI_H__
#define __UnlockMe_APPUI_H__


// INCLUDES
#include <aknViewAppUi.h>
#include <akntabgrp.h>
#include <aknnavide.h>
#include "TimeOutNotifier.h"
#include "phone.h"

// CLASS DECLARATION

/**
* CUnlockMeAppUi application UI class.
* An instance of class CUnlockMeAppUi is the UserInterface part of the AVKON
* application framework for the UnlockMe example application
*/
class CUnlockMeAppUi : public CAknViewAppUi, public MTimeOutNotifier
    {

    public: // Constructors and destructor

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    public: // New functions from CAknAppUi

        /**
		* HandleCommandL
        * Takes care of command handling.
        * @param aCommand Command to be handled.
        */
        void HandleCommandL( TInt aCommand );
		
		void SaveSettingsL();

        /**
        * ~CAknExNoteAppUi
        * Virtual Destructor.
        */     
        virtual ~CUnlockMeAppUi();

		// TimeOutNotifier
        void TimerExpiredL();

	private:    // From MEikMenuObserver
				/** 
				* From MEikMenuObserver
				* @param aResourceId menu pane resource ID
				* @param aMenuPane menu pane pointer
        */
        void DynInitMenuPaneL( TInt aResourceId, CEikMenuPane* aMenuPane );

        virtual TKeyResponse HandleKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType);

    private: // Data
		CAknNavigationDecorator*        iDecoratedTabGroup;	// Own
    };


#endif // __UnlockMe_APPUI_H__

// End of File



















