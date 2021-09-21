/* Copyright (c) 2003, Nokia. All rights reserved */


#ifndef __CSMSHANDLER_H__
#define __CSMSHANDLER_H__

//  INCLUDES
#include <e32base.h>
#include <msvapi.h>
#include <mtuireg.h>
#include "flashsms.hrh"

// CONSTANTS
const TInt KBfrLength = 20;

// FORWARD DECLARATIONS
class CClientMtmRegistry;
class CSmsClientMtm;

// CLASS DECLARATION
/**
* CSmsHandler application engine class.
* Takes care of sending and receiveing SMS messages using the SMS client MTM.
* Interacts with the application UI class.
*/
class CSmsHandler : public CBase, public MMsvSessionObserver
    {
    public: // Constructors and destructor

        /**
        * NewL.
        * Two-phased constructor.
        * @param aSmsAppUi Pointer to AppUi instance.
        * @return Pointer to the created instance of CSmsHandler.
        */
        static CSmsHandler* NewL();

        /**
        * NewLC.
        * Two-phased constructor.
        * @param aSmsAppUi Pointer to AppUi instance.
        * @return Pointer to the created instance of CSmsHandler.
        */
        static CSmsHandler* NewLC();

        /**
        * ~CSmsHandler
        * Destructor.
        */
        virtual ~CSmsHandler();

    public: // New functions

        /**
        * SendL.
        * Starts the process of creating and sending an SMS message.
        * @param aRecipientNumber The number of the recipent.
        * @param aMessageText The message text.
        * @return ETrue if successful, EFalse if not.
        */
       TBool SendL( const TDesC& aRecipientNumber,
                    const TDesC& aMessageText );

    public: // Functions from base classes

		void DeleteFailedL();
        /**
        * From MMsvSessionObserver, HandleSessionEventL.
        * Handles notifications of events from the Message Server.
        * @param aEvent The event that has taken place
        * @param aArg1 Event type-specific argument value
        * @param aArg2 Event type-specific argument value
        * @param aArg3 Event type-specific argument value
        */
        void HandleSessionEventL( TMsvSessionEvent aEvent, TAny* aArg1,
                                  TAny* aArg2, TAny* aArg3 );


    private: // Constructors

        /**
        * CSmsHandler.
        * C++ default constructor.
        * @param aSmsAppUi Pointer to AppUi instance.
        */
        CSmsHandler();

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    private: // New functions

        /**
        * AccessMtmL.
        * Access the MTM Registry and create an SMS specific Client MTM instance.
        */
        void AccessMtmL();


        /**
        * CreateMsgL.
        * Create an SMS message.
        * @return ETrue if successful, EFalse is unsuccessful.
        */
	    TBool CreateMsgL();

        /**
        * ScheduleL.
        * Schedule an SMS message for sending.
        */
        void ScheduleL();

  
        /**
        * ValidateL.
        * Validate an SMS message.
        * @return ETrue if successful, EFalse is unsuccessful.
        */
        TBool ValidateL();

    private: // Data

        /**
        * iSession, the contact database.
        * Owned by CSmsHandler object.
        */
        CMsvSession* iSession;

        /**
        * iMtmRegistry, client MTM registry.
        * Owned by CSmsHandler object.
        */
        CClientMtmRegistry* iMtmRegistry;

        /**
        * iSmsMtm, SMS specific Client MTM.
        * Owned by CSmsHandler object.
        */
        CSmsClientMtm* iSmsMtm;

        /**
        * iOperation, the current message server operation.
        * Owned by CSmsHandler object.
        */
//        CMsvOperation* iOperation;

        /**
        * iRecipientNumber, telephone number of the recipient.
        */
        TBuf<EMaxTelephoneNumberLength> iRecipientNumber;

        /**
        * iMessageText, SMS message text.
        */
        TBuf<EMaxMessageLength> iMessageText;

        /**
        * iMtmUiRegistry, User Interface MTM Registry.
        * Owned by CSmsHandler object.
        */
        CMtmUiRegistry* iMtmUiRegistry;

        /**
        * iSelection, entry selection to hold received messages.
        * Owned by CSmsHandler object.
        */
//        CMsvEntrySelection* iSelection;
    };

#endif // __CSMSHANDLER_H__

