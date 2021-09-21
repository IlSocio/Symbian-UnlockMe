// TIMEOUTNOTIFIER.H
//
// Copyright ( c ) 1997-1999 Symbian Ltd.  All rights reserved.
//


#ifndef __TIMEOUTNOTIFIER_H__
#define __TIMEOUTNOTIFIER_H__

// CLASS DECLARATION
/**
* MTimeOutNotifier
*  This class specifies the function to be called when a timeout occurs.
*  Used in conjunction with CTimeOutTimer class.
*/
class MTimeOutNotifier
    {
    public: // New functions

        /**
        * TimerExpired.
        * The function to be called when a timeout occurs.
        */
        virtual void TimerExpiredL() = 0;
    };

#endif // __TIMEOUTNOTIFIER_H__

// End of File