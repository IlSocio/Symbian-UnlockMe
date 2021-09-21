/* Copyright (c) 2004, Nokia. All rights reserved */


// INCLUDE FILES
#include "TimeOutTimer.h"
#include "TimeOutNotifier.h"

// ========================= MEMBER FUNCTIONS ==================================

// -----------------------------------------------------------------------------
// CTimeOutTimer::NewL()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CTimeOutTimer* CTimeOutTimer::NewL( const TInt aPriority,
                                    MTimeOutNotifier& aTimeOutNotify )
    {
    CTimeOutTimer* self = CTimeOutTimer::NewLC( aPriority, aTimeOutNotify );
    CleanupStack::Pop( self );
    return self;
    }

// -----------------------------------------------------------------------------
// CTimeOutTimer::NewLC()
// Two-phased constructor.
// -----------------------------------------------------------------------------
//
CTimeOutTimer* CTimeOutTimer::NewLC( const TInt aPriority,
                                     MTimeOutNotifier& aTimeOutNotify )
    {
    CTimeOutTimer* self = new ( ELeave ) CTimeOutTimer( aPriority,
                                                        aTimeOutNotify );
    CleanupStack::PushL( self );
    self->ConstructL();
    return self;
    }

// -----------------------------------------------------------------------------
// CTimeOutTimer::CTimeOutTimer()
// C++ default constructor can NOT contain any code, that might leave.
// -----------------------------------------------------------------------------
//
CTimeOutTimer::CTimeOutTimer( const TInt aPriority,
                              MTimeOutNotifier& aTimeOutNotify )
: CTimer( aPriority ), iNotify( aTimeOutNotify )
    {
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CTimeOutTimer::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CTimeOutTimer::ConstructL()
    {
    CTimer::ConstructL();
    CActiveScheduler::Add( this );
    }

// -----------------------------------------------------------------------------
// CTimeOutTimer::~CTimeOutTimer()
// Destructor.
// -----------------------------------------------------------------------------
//
CTimeOutTimer::~CTimeOutTimer()
    {
	Cancel();
    // No implementation required
    }

// -----------------------------------------------------------------------------
// CTimeOutTimer::RunL()
// Called when operation completes.
// -----------------------------------------------------------------------------
//
void CTimeOutTimer::RunL()
    {
    // Timer request has completed, so notify the timer's owner
    if ( iStatus == KErrNone )
        {
        iNotify.TimerExpiredL();
        }
/*    else
        {
        User::Panic( KPanicSockets, ESocketsBadStatus );
        }*/
    }

// End of File