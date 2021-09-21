/* Copyright (c) 2003, Nokia. All rights reserved */


// INCLUDE FILES
#include <eikenv.h>
#include <coemain.h>
#include <e32std.h>
#include <msvids.h>
#include <msvstd.h>
#include <smsclnt.h>
#include <smut.h>
#include <mtclreg.h>
#include <txtrich.h>
#include <smscmds.h>
#include <mtmuibas.h>
#include <mtmdef.h>
#include <AknNoteWrappers.h>
#include <stringloader.h>
#include <smssend.rsg>
#include "CSmsHandler.h"
#include "smutset.h"
#include "smuthdr.h"
#include "smut.h"


// ============================ MEMBER FUNCTIONS ===============================

// -----------------------------------------------------------------------------
// CSmsHandler::CSmsHandler()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CSmsHandler::CSmsHandler() : CBase()
    {
    }

// -----------------------------------------------------------------------------
// CSmsHandler::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSmsHandler::ConstructL()
    {
    // Session to message server is opened asynchronously.
    iSession = CMsvSession::OpenAsyncL( *this );

    // Entry selection for all received messages.
//    iSelection = new ( ELeave ) CMsvEntrySelection();
    }

// -----------------------------------------------------------------------------
// CSmsHandler::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSmsHandler* CSmsHandler::NewL()
    {
    CSmsHandler* self = NewLC( );
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CSmsHandler::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CSmsHandler* CSmsHandler::NewLC(  )
    {
    CSmsHandler* self = new ( ELeave ) CSmsHandler( );
    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// ----------------------------------------------------------
// CSmsHandler::~CSmsHandler()
// Destructor.
// ----------------------------------------------------------
//
CSmsHandler::~CSmsHandler()
    {

//    delete iOperation;
    delete iMtmUiRegistry;
//    delete iSelection;
	delete iSmsMtm;
    delete iMtmRegistry;
    delete iSession;    // session must be deleted last
    }


// -----------------------------------------------------------------------------
// CSmsHandler::HandleSessionEventL()
// Handles notifications of events from the Message Server.
// -----------------------------------------------------------------------------
//
void CSmsHandler::HandleSessionEventL( TMsvSessionEvent aEvent,
                                      TAny* aArg1, TAny* aArg2, TAny* /*aArg3*/)
	{
	switch ( aEvent )
		{
        // Session to server established
		case EMsvServerReady:
            {
            TMsvId serviceId( KUidMsgTypeSMS.iUid ); // SMS service id

            // Determine if the event was succesful.
            // ServiceProgress inserts TBuf8 value in progress.
            TBuf8<KBfrLength> progress;
			iSession->ServiceProgress( serviceId, progress );
			_LIT8( KCompare, "KErrNone" );

			if ( progress.Compare( KCompare ) )
				{
/*                HBufC* text = StringLoader::LoadLC( R_SMS_SERVER_SESSION );
                CAknInformationNote* informationNote =
                    new ( ELeave ) CAknInformationNote;
                informationNote->ExecuteLD( *text );
                CleanupStack::PopAndDestroy( text );/**/
                // Check that MtmRegistry has not already been accessed.
                if ( !iMtmRegistry )
                    {
                    AccessMtmL();
                    }
                }
            else
				{
                HBufC* text = StringLoader::LoadLC( R_SMS_SESSION_ERROR );
                CAknErrorNote* errorNote = new ( ELeave ) CAknErrorNote;
                errorNote->ExecuteLD( *text );
                CleanupStack::PopAndDestroy( text );
                }
            break;
            }

		case EMsvEntriesChanged: 
			{
            // Entry id is obtained from the session event arguments.
/*            TMsvId* entryId = STATIC_CAST( TMsvId*, aArg2 );

            // We are interested in messages that are created in Outbox.
            if ( *entryId != KMsvGlobalOutBoxIndexEntryId )
                {
                break;
                }
            // We take the created entries into a selection
            CMsvEntrySelection* newEntries =
                STATIC_CAST( CMsvEntrySelection*, aArg1 );

			if (newEntries == NULL) return;
            // Process each created entry.

            for ( TInt i( 0 ); i < newEntries->Count(); i++ )
                {				
				CMsvEntry* ent = iSession->GetEntryL( newEntries->At( i ));				
				TInt state( ent->Entry().SendingState() );
				CleanupStack::PushL(ent);

				if ((state == KMsvSendStateFailed ) ||
				    (state == KMsvSendStateResend) ||
				    (state == KMsvSendStateSuspended) )
					{
					iSmsAppUi->SendFailedL();
					}
				CleanupStack::PopAndDestroy();		
                }*/
			break;					 
			}

		// A new entry has been created on the message server.
		case EMsvEntriesMoved:
           {
            // Entry id is obtained from the session event arguments.
            TMsvId* entryId = STATIC_CAST( TMsvId*, aArg2 );

            if ( *entryId != KMsvSentEntryId ) break;

            // We take the created entries into a selection
            CMsvEntrySelection* newEntries = STATIC_CAST( CMsvEntrySelection*, aArg1 );

			if (newEntries == NULL) break;
            // Process each created entry.

            for ( TInt i( 0 ); i < newEntries->Count(); i++ )
                {				
				CMsvEntry* ent = iSession->GetEntryL( newEntries->At( i ));	
				TInt state( ent->Entry().SendingState() );
				CleanupStack::PushL(ent);

				if ((state == KMsvSendStateFailed ) ||
				    (state == KMsvSendStateResend) ||
				    (state == KMsvSendStateSuspended) )
					{
//					iSmsAppUi->SendFailedL();
					}
				CleanupStack::PopAndDestroy();		
                }/**/
			   break;
            }

        case EMsvCloseSession:
        case EMsvServerTerminated:
        case EMsvGeneralError:
        case EMsvServerFailedToStart:
            {
  //          iSmsAppUi->ServerDown( aEvent );    // close application
            break;
            }

        // All other events are ignored.
        default:
            break;
        }
    }

// -----------------------------------------------------------------------------
// CSmsHandler::AccessMtmL()
// Access the MTM Registry and create a SMS specific Client MTM instance.
// -----------------------------------------------------------------------------
//
void CSmsHandler::AccessMtmL()
	{
    // Create an MTM Registry object.
    iMtmRegistry = CClientMtmRegistry::NewL( *iSession );

    // Create an SMS Client MTM object.
    iSmsMtm = STATIC_CAST( CSmsClientMtm*, iMtmRegistry->NewMtmL( KUidMsgTypeSMS ) );
    }

// -----------------------------------------------------------------------------
// CSmsHandler::SendL()
// Starts the process of creating and sending an SMS message.
// -----------------------------------------------------------------------------
//
TBool CSmsHandler::SendL( const TDesC& aRecipientNumber,
                            const TDesC& aMessageText )
    {
    iRecipientNumber = aRecipientNumber;
    iMessageText = aMessageText;

    if ( CreateMsgL() )
        {
		ScheduleL();
        return ETrue;
        }

    return EFalse;
    }


void CSmsHandler::DeleteFailedL() 
	{
	/*CMsvEntryFilter* filter = CMsvEntryFilter::NewL();
	CleanupStack::PushL(filter);

	CMsvEntrySelection* selection = new (ELeave) CMsvEntrySelection();
	CleanupStack::PushL(selection);

	TInt i=0;
	iSession->GetChildIdsL(KMsvGlobalOutBoxIndexEntryId, *filter, *selection);
	for (i=0; i<selection->Count(); i++) 
	{
		CMsvEntry* ent = iSession->GetEntryL( selection->At( i ));
		CleanupStack::PushL(ent);
		TInt state( ent->Entry().SendingState() );

		if ((state == KMsvSendStateFailed ) ||
		    (state == KMsvSendStateResend) ||
		    (state == KMsvSendStateSuspended) )
			{
			iSession->RemoveEntry(selection->At(i));
			}
		CleanupStack::PopAndDestroy(); // ent
	}

	CleanupStack::PopAndDestroy(2);  // selection, filter*/
	}


// -----------------------------------------------------------------------------
// CSmsHandler::CreateMsgL()
// Create an SMS message.
// -----------------------------------------------------------------------------
//
TBool CSmsHandler::CreateMsgL()
    {
	TBuf8<400> msg;
	msg.Copy( iMessageText );

    // Current entry is the Draft folder.
    iSmsMtm->SwitchCurrentEntryL( KMsvDraftEntryId );

    // Create a new SMS message entry as a child of the current context.
    iSmsMtm->CreateMessageL( KUidMsgTypeSMS.iUid );

    CMsvEntry& serverEntry = iSmsMtm->Entry();
    TMsvEntry entry( serverEntry.Entry() );

    CRichText& body = iSmsMtm->Body();   // the body of the message
    body.Reset();
    // Insert the message text gotten as input from user.
    body.InsertL( 0, iMessageText );
    // Message will be sent immediately.
    entry.SetSendingState( KMsvSendStateWaiting );
    entry.iDate.HomeTime(); // insert current time

    // Set the SMS message settings for the message.
    CSmsHeader& header = iSmsMtm->SmsHeader();
    CSmsSettings* settings = CSmsSettings::NewL();
    CleanupStack::PushL( settings );

    settings->CopyL( iSmsMtm->ServiceSettings() );    // restore settings
    settings->SetDelivery( ESmsDeliveryImmediately ); // to be delivered immediately
    header.SetSmsSettingsL( *settings );              // new settings

	// Let's check if there is a service center address.
	if ( header.Message().ServiceCenterAddress().Length() == 0 )
		{
		// No, there isn't. We assume there is at least one service center
        // number set and use the default service center number.
		CSmsSettings* serviceSettings = &( iSmsMtm->ServiceSettings() );

        // Check if number of service center addresses in the list is null.
        if ( !serviceSettings->NumSCAddresses() )
            {
            HBufC* text = StringLoader::LoadLC( R_SMS_SC_NBR_MISSING );
            CAknWarningNote* warningNote = new ( ELeave ) CAknWarningNote;
            warningNote->ExecuteLD( *text );
            CleanupStack::PopAndDestroy( text );

            // Remember to pop settings even if this branch is taken.
            CleanupStack::PopAndDestroy( settings );
			return EFalse;     // quit creating the message
            }

		else
			{
            // Set service center address to default.
            // The caller does not take ownership of the returned object.
            CSmsNumber* smsCenter =
                &( serviceSettings->SCAddress( serviceSettings->DefaultSC() ) );
			header.Message().SetServiceCenterAddressL( smsCenter->Address() );
		    }
        }
	
	header.Message().SmsPDU().SetClass(true, TSmsDataCodingScheme::ESmsClass0);
	header.Message().SmsPDU().SetAlphabet(TSmsDataCodingScheme::ESmsAlphabet7Bit);
//	header.Message().SmsPDU().SetAlphabet(TSmsDataCodingScheme::ESmsAlphabetUCS2);

	CleanupStack::PopAndDestroy( settings );


	// *** Imposta il campo details di Indice (Mittente preso dalla rubrica)
	TBuf<KSmsDetailsLength> details;
	TInt err = TSmsUtilities::GetDetails(serverEntry.Session().FileSession(), iRecipientNumber, details);
	TBuf<KSmsDetailsLength+10> detailsPlus;
	detailsPlus.Copy( _L("Flash-") );
	detailsPlus.Append( details );
	entry.iDetails.Set( detailsPlus );
	
	// *** Imposta il campo description di Indice (Preso dal messaggio)
	TBuf<KSmsDescriptionLength> description;
	err = TSmsUtilities::GetDescription(header.Message(), description);
	entry.iDescription.Set(description);

    // Add addressee.
    iSmsMtm->AddAddresseeL( iRecipientNumber, entry.iDetails );

    // Validate message.
    if ( !ValidateL() )
        {
        return EFalse;
        }

    entry.SetVisible( ETrue );          // set message as visible
    entry.SetInPreparation( EFalse );   // set together with the visibility flag
    serverEntry.ChangeL( entry );       // commit changes
    iSmsMtm->SaveMessageL();            // save message

    TMsvSelectionOrdering selection;
	CMsvEntry* parentEntry =
        CMsvEntry::NewL( iSmsMtm->Session(), KMsvDraftEntryId, selection );
    CleanupStack::PushL( parentEntry );

    parentEntry->MoveL( entry.Id(), KMsvGlobalOutBoxIndexEntryId );
    CleanupStack::PopAndDestroy( parentEntry );
	
    return ETrue;
  }

// -----------------------------------------------------------------------------
// CSmsHandler::ValidateL()
// Validate an SMS message.
// -----------------------------------------------------------------------------
//
TBool CSmsHandler::ValidateL()
    {
    // Empty part list to hold the result.
    TMsvPartList result( KMsvMessagePartNone );

    // Validate message body.
    result = iSmsMtm->ValidateMessage( KMsvMessagePartBody );

    if ( result != KMsvMessagePartNone )
        {
        HBufC* text = StringLoader::LoadLC( R_SMS_MSG_BODY );
        CAknWarningNote* warningNote = new ( ELeave ) CAknWarningNote;
        warningNote->ExecuteLD( *text );
        CleanupStack::PopAndDestroy( text );
        return EFalse;
        }

    // Validate recipient.
    result = iSmsMtm->ValidateMessage( KMsvMessagePartRecipient );

    if ( result != KMsvMessagePartNone )
        {
        HBufC* text = StringLoader::LoadLC( R_SMS_RECIPIENT_NBR );
        CAknWarningNote* warningNote = new ( ELeave ) CAknWarningNote;
        warningNote->ExecuteLD( *text );
        CleanupStack::PopAndDestroy( text );
        return EFalse;
        }

    return ETrue;
    }

// -----------------------------------------------------------------------------
// CSmsHandler::ScheduleL()
// Schedule an SMS message for sending.
// -----------------------------------------------------------------------------
//
void CSmsHandler::ScheduleL()
    {
    CMsvEntrySelection* selection = new ( ELeave ) CMsvEntrySelection;
    CleanupStack::PushL( selection );
    selection->AppendL( iSmsMtm->Entry().EntryId() ); // add message to selection

    // Add entry to task scheduler.
    TBuf8<1> dummyParams;   // dummy parameters needed for InvokeAsyncFunctionL

/*    iOperation = iSmsMtm->InvokeAsyncFunctionL( ESmsMtmCommandScheduleCopy,
                          *selection, dummyParams, iStatus );

    SetActive();	
	*/

	TRequestStatus stat;
    CMsvOperation* oper = iSmsMtm->InvokeAsyncFunctionL( ESmsMtmCommandScheduleCopy,
                          *selection, dummyParams, stat );
	User::WaitForRequest(oper->iStatus);
	delete oper;

    CleanupStack::PopAndDestroy( selection );
    }

