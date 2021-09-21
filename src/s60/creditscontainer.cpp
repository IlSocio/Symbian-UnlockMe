

// INCLUDE FILES
#include "CreditsContainer.h"
#include <AknLists.h>
#include <barsread.h>
#include <Unlockme.rsg>
#include <Unlockme.mbg> // Contiene i numeri delle icone di Unlockme.mbm


// -----------------------------------------------------------------------------
// CCreditsContainer::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CCreditsContainer::ConstructL( const TRect& aRect )
    {
    CreateWindowL();
	y=aRect.Height();
	iTimer = CTimeOutTimer::NewL(EPriorityAbsoluteHigh, *this);
	iBitmap = iEikonEnv->CreateBitmapL(KImgLocation, EMbmUnlockmeSplashbg);
    SetRect( aRect );
    ActivateL();
	TimerExpiredL();
	}


CCreditsContainer::~CCreditsContainer() 
	{
	if (iTimer) 
	{
		iTimer->Cancel();
		delete iTimer;
	}
	if (iBitmap) delete iBitmap;
	}
// -----------------------------------------------------------------------------
// CCreditsContainer::CountComponentControls() const
// returns number of controls inside this container.
// -----------------------------------------------------------------------------
//
TInt CCreditsContainer::CountComponentControls() const
    {
	TInt count(0);
//	if (iEditor) count++;
    return count;
    }

// -----------------------------------------------------------------------------
// CCreditsContainer::ComponentControl() const
// returns pointer of controls inside this container
// -----------------------------------------------------------------------------
//
CCoeControl* CCreditsContainer::ComponentControl( TInt aIndex ) const
    {
	 switch ( aIndex )
		{
//		case 0:
//			return iEditor;
		default:
			return NULL;
		}
    }


void CCreditsContainer::SizeChanged()
{
	//
	// Set the screen area where the listbox will be displayed.
	// 
//    if(iEditor)
//		iEditor->SetRect(Rect());
}


void CCreditsContainer::TimerExpiredL() 
{
	y-=1;
	if (y<-275) y=this->Rect().Height();
	DrawDeferred();
	TTimeIntervalMicroSeconds32 interv(1000000/20); // 1 ventesimo di sec.
	iTimer->After(interv);
}


void CCreditsContainer::DrawText( const TDesC& text, int posy, const CFont* font) const
	{
    CWindowGc& gc = SystemGc();
	gc.UseFont(font);

	gc.SetPenColor(KRgbGray);
	gc.DrawText(text, TRect(2, y+posy+1, Rect().Width(), y+posy+font->HeightInPixels()+5), font->AscentInPixels(), CGraphicsContext::ECenter);
	
	gc.SetPenColor(KRgbBlack);
	gc.DrawText(text, TRect(0, y+posy, Rect().Width(), y+posy+font->HeightInPixels()+5), font->AscentInPixels(), CGraphicsContext::ECenter);
	gc.DiscardFont();
	}

// -----------------------------------------------------------------------------
// CCreditsContainer::Draw() const
// Draws the display
// -----------------------------------------------------------------------------
//
void CCreditsContainer::Draw( const TRect& aRect ) const
    {
    CWindowGc& gc = SystemGc();
    gc.SetBrushStyle(CGraphicsContext::ENullBrush);
    gc.SetPenStyle(CGraphicsContext::ESolidPen);
	if (iBitmap) {
		gc.SetFaded(true);
		gc.BitBlt(TPoint(0, 0), iBitmap);
		gc.SetFaded(false);
	}

	DrawText( _L("Research & Development:"), 0, iEikonEnv->LegendFont() );
	DrawText( _L("Marco Bellino"), 15, iEikonEnv->DenseFont() );
	DrawText( _L("m.bellino@symbian-toys.com"), 30, iEikonEnv->DenseFont() );

	DrawText( _L("Graphics & Logo:"), 60, iEikonEnv->LegendFont() );
	DrawText( _L("Francesco Moretta"), 75, iEikonEnv->DenseFont() );
	DrawText( _L("amorf@hotmail.it"), 90, iEikonEnv->DenseFont() );

//	DrawText( _L("Translations:"), 120, iEikonEnv->LegendFont() );
//	DrawText( _L("Nicola Lo Buono"), 135, iEikonEnv->DenseFont() );
//	DrawText( _L("alocin82@gmail.com"), 150, iEikonEnv->DenseFont() );

/*	DrawText( _L("Greets fly out to:"), 120, iEikonEnv->LegendFont() );
	DrawText( _L("www.quellicheilcell.it"), 135, iEikonEnv->DenseFont() );
	DrawText( _L("www.nokiaworld.it"), 150, iEikonEnv->DenseFont() );
	DrawText( _L("www.serie60.it"), 165, iEikonEnv->DenseFont() );
	DrawText( _L("www.nokioteca.net"), 180, iEikonEnv->DenseFont() );*/

//	DrawText( _L("Special:"), 180, iEikonEnv->LegendFont() );
//	DrawText( _L("My Girlfriend Roberta"), 195, iEikonEnv->DenseFont() );

	
//	if (iBitmap) 
//		gc.BitBlt(TPoint(0, 0), iBitmap);
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
    gc.DrawText(_L("Unlockme 0.99a"),rect,font->AscentInPixels(),CGraphicsContext::ECenter);

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

