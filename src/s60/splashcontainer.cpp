

// INCLUDE FILES
#include "SplashContainer.h"
#include <AknLists.h>
#include <barsread.h>
#include <UnlockMe.rsg>
#include <UnlockMe.mbg> // Contiene i numeri delle icone di UnlockMe.mbm

// -----------------------------------------------------------------------------
// CSplashContainer::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSplashContainer::ConstructL( const TRect& aRect )
    {
    CreateWindowL();

//    iBackgroundImage = iEikonEnv->CreateBitmapL
//								( KMultiBitmapFilename,EMbmImagesImage1 );
	iBitmap = iEikonEnv->CreateBitmapL(KImgLocation, EMbmUnlockmeSplash);
//	User::LeaveIfError( iBitmap->Load(KImgLocation, 0) );
//	iListBox = new (ELeave) CAknDoubleNumberStyleListBox();
//	iListBox->ConstructL(this, EAknListBoxSelectionList);
//	UpdateListBoxViewL();
	
    SetRect( aRect );
    ActivateL();
	}

/*
void UpdateListBoxViewL()
	{
//	iListBox->HandleItemAdditionL();
//  iListBox->ActivateL();
//  iListBox->DrawNow();																																																																																																				
	}
*/

CSplashContainer::~CSplashContainer() 
	{
	if (iBitmap) delete iBitmap;
	}
// -----------------------------------------------------------------------------
// CSplashContainer::CountComponentControls() const
// returns number of controls inside this container.
// -----------------------------------------------------------------------------
//
TInt CSplashContainer::CountComponentControls() const
    {
	TInt count(0);
//	if (iEditor) count++;
    return count;
    }

// -----------------------------------------------------------------------------
// CSplashContainer::ComponentControl() const
// returns pointer of controls inside this container
// -----------------------------------------------------------------------------
//
CCoeControl* CSplashContainer::ComponentControl( TInt aIndex ) const
    {
	 switch ( aIndex )
		{
//		case 0:
//			return iEditor;
		default:
			return NULL;
		}
    }


void CSplashContainer::SizeChanged()
{
	//
	// Set the screen area where the listbox will be displayed.
	// 
//    if(iEditor)
//		iEditor->SetRect(Rect());
}



// -----------------------------------------------------------------------------
// CSplashContainer::Draw() const
// Draws the display
// -----------------------------------------------------------------------------
//

void CSplashContainer::Draw( const TRect& aRect ) const
    {
    CWindowGc& gc = SystemGc();
	TRect  rect = aRect;
    //
    // Draw Black background
    //
    gc.SetPenStyle(CGraphicsContext::ENullPen);
    gc.SetBrushStyle(CGraphicsContext::ESolidBrush);
    gc.SetBrushColor(KRgbBlack);
    gc.DrawRect(rect);
	if (iBitmap) 
		gc.BitBlt(TPoint(0, 0), iBitmap);
//		gc.DrawBitmap(aRect, iBitmap);
//TODO: Visualizza l'immagine
/*    //
    // Select default font for title
    // The color will change from black -> white with the increase of iColorCount
    //iEikonEnv
	
    const CFont* font = iEikonEnv->TitleFont();
    gc.UseFont(font);
    gc.SetPenStyle(CGraphicsContext::ESolidPen);
    gc.SetPenColor( KRgbGray );

    //
    // Draw the text, horizontally centered and vertically slightly below center
    //
    TSize aSize(rect.Width(),font->HeightInPixels()+5);
    rect.SetRect(TPoint(0,(rect.Height()/2)-font->HeightInPixels()-5),aSize);
    gc.DrawText(_L("UnlockMe 0.99a"),rect,font->AscentInPixels(),CGraphicsContext::ECenter);

    rect.Move(0,font->HeightInPixels() +2);
    gc.DrawText(_L("Beta Version"),rect,font->AscentInPixels(),CGraphicsContext::ECenter);
 
    gc.DiscardFont();

    font = iEikonEnv->NormalFont();
    gc.UseFont(font);
    rect.Move(0,font->HeightInPixels()*4 +2);
    gc.DrawText(_L("Il.Socio"),rect,font->AscentInPixels(),CGraphicsContext::ECenter);
    gc.DiscardFont();*/
    }

// End of File


	/*
	NON E' COMPITO MIO

	Questa e'  la storia di quattro persone chiamate:
	Ognuno, Qualcuno, Ciascuno, e Nessuno.

	C'era un lavoro da fare e Ognuno era sicuro 
	che Qualcuno l'avrebbe fatto. Ciascuno 
	avrebbe potuto farlo, ma Nessuno lo fece.

	Qualcuno si arrabio' perche' era lavoro di 
	Ognuno; Ognuno penso' che Ciascuno potera 
	farlo, ma Nessuno capi' che Ognuno non 
	l'avrebbe fatto.

    Fini' che Ognuno incolpo' Qualcuno perche' 
	Nessuno fece cio' che Ciascuno avrebbe 
	potuto fare.
	*/

