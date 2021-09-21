/* Copyright (c) 2004, Nokia. All rights reserved */


#ifndef __TIMEOUTTIMER_H__
#define __TIMEOUTTIMER_H__

// INCLUDES
#include <e32base.h>

// FORWARD DECLARATIONS
class MTimeOutNotifier;

// CLASS DECLARATION
/**
* CTimeOutTimer
*  This class will notify an object after a specified timeout.
*/
class CTimeOutTimer : public CTimer
    {
    public: // Constructors and destructors

        /**
        * NewL.
        * Two-phased constructor.
        * Creates a CTimeOutTimer object using two phase construction,
        * and returns a pointer to the created object.
        * @param aPriority Priority to use for this timer.
        * @param aTimeOutNotify Object to notify of timeout event.
        * @return A pointer to the created instance of CTimeOutTimer.
        */
        static CTimeOutTimer* NewL( const TInt aPriority,
                                    MTimeOutNotifier& aTimeOutNotify );

        /**
        * NewLC.
        * Two-phased constructor.
        * Creates a CTimeOutTimer object using two phase construction,
        * and returns a pointer to the created object.
        * @param aPriority Priority to use for this timer.
        * @param aTimeOutNotify Object to notify of timeout event.
        * @return A pointer to the created instance of CTimeOutTimer.
        */
        static CTimeOutTimer* NewLC( const TInt aPriority,
                                     MTimeOutNotifier& aTimeOutNotify );

        /**
        * ~CTimeOutTimer.
        * Destructor.
        * Destroys the object and release all memory objects.
        */
        virtual ~CTimeOutTimer();

    protected: // Functions from base classes

        /**
        * From CActive, RunL.
        * Called when operation completes.
        */
        void RunL();

    private: // Constructors and destructors

        /**
        * CTimeOutTimer.
        * C++ default constructor.
        * Performs the first phase of two phase construction.
        * @param aPriority Priority to use for this timer.
        * @param aTimeOutNotify An observer to notify.
        */
        CTimeOutTimer( const TInt aPriority,
                       MTimeOutNotifier& aTimeOutNotify );

        /**
        * ConstructL.
        * 2nd phase constructor.
        */
        void ConstructL();

    private: // Data

        /**
        * iNotify, the observer for this objects events.
        */
        MTimeOutNotifier& iNotify;
    };

#endif // __TIMEOUTTIMER_H__

// End of File