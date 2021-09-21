/* Copyright (c) 2004, Nokia. All rights reserved */

#ifndef __UnlockMe_PAN__
#define __UnlockMe_PAN__


// MultiViews application panic codes 
enum TUnlockMePanics 
    {
    EUnlockMeBasicUi = 1
    // add further panics here
    };

inline void Panic( TUnlockMePanics aReason )
    {
    _LIT( applicationName,"UnlockMe" );
    User::Panic( applicationName, aReason );
    }

#endif // __MULTIVIEWS_PAN__

// End of File