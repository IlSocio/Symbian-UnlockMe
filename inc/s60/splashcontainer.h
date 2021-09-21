


#ifndef __SPLASH_CONTAINER_H__
#define __SPLASH_CONTAINER_H__

// INCLUDES
#include <aknview.h>
#include <eikrted.h>


//#ifdef __WINS__
//	_LIT(KImgLocation,"z:\\system\\apps\\flashsms\\flashsms.mbm");
//#else
	_LIT(KImgLocation,"\\system\\apps\\unlockme\\unlockme.mbm");
//#endif


/**
*  CSplashContainer container control class.
*  An instance of CSplashContainer contains the view drawn to the screen
*  for View1
*/
class CSplashContainer : public CCoeControl
    {
    public: // Constructors and destructor

        /**
        * ConstructL
        * 2nd phase constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL( const TRect& aRect );
		~CSplashContainer();


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
	private:
		CFbsBitmap* iBitmap;
    };

#endif // ___CONTAINER1_H__


// End of File