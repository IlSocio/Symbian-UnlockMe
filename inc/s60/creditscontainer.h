/* Copyright (c) 2004, Nokia. All rights reserved */



#ifndef __CREDITS_CONTAINER_H__
#define __CREDITS_CONTAINER_H__

// INCLUDES
#include <aknview.h>
#include <eikrted.h>
#include "timeoutnotifier.h"
#include "timeouttimer.h"

//#ifdef __WINS__
//	_LIT(KImgLocation,"z:\\system\\apps\\guardian\\guardian.mbm");
//#else
	_LIT(KImgLocation,"\\system\\apps\\unlockme\\unlockme.mbm");
//#endif


/**
*  CCreditsContainer container control class.
*  An instance of CCreditsContainer contains the view drawn to the screen
*  for View1
*/
class CCreditsContainer : public CCoeControl, public MTimeOutNotifier
    {
    public: // Constructors and destructor

        /**
        * ConstructL
        * 2nd phase constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL( const TRect& aRect );
		~CCreditsContainer();


    public: // from CoeControl
		//TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

        /**
        * CountComponentControls
        * @return number of controls inside this container.
        */
        TInt CountComponentControls() const;

        /**
        * ComponentControl
        * @param Index number of the control.
        * @return Pointer of controls inside this container.
        */
        CCoeControl* ComponentControl( TInt aIndex ) const;

		void SizeChanged();
		void Draw( const TRect& aRect ) const;

        void TimerExpiredL();
		void DrawText( const TDesC& text, int y, const CFont* font) const;

	private:
		CTimeOutTimer* iTimer;
		CFbsBitmap* iBitmap;
		TInt y;
    };

#endif // ___CONTAINER1_H__


// End of File