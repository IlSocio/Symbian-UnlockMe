/* Copyright (c) 2004, Nokia. All rights reserved */



#ifndef __ABOUT_CONTAINER_H__
#define __ABOUT_CONTAINER_H__



// INCLUDES
#include <aknview.h>
#include <eikrted.h>

/**
*  CAboutContainer container control class.
*  An instance of CAboutContainer contains the view drawn to the screen
*  for View1
*/
class CAboutContainer : public CCoeControl
    {
    public: // Constructors and destructor
		TBuf<10> iCount;

        /**
        * ConstructL
        * 2nd phase constructor.
        * @param aRect Frame rectangle for container.
        */
        void ConstructL( const TRect& aRect );
		~CAboutContainer();


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
		void DrawText( const TDesC& text, int y, const CFont* font) const; 

		TBuf<30> iText;
	private:
		CFbsBitmap* iBitmap;
    };

#endif // ___CONTAINER1_H__


// End of File