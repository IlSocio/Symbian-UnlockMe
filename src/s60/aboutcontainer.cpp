/* Copyright (c) 2004, Nokia. All rights reserved */


// INCLUDE FILES
#include "AboutContainer.h"
#include <AknLists.h>
#include <barsread.h>
#include <unlockme.rsg>
#include <unlockme.mbg>

// -----------------------------------------------------------------------------
// CAboutContainer::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CAboutContainer::ConstructL( const TRect& aRect )
    {
    CreateWindowL();

//	iListBox = new (ELeave) CAknDoubleNumberStyleListBox();
//	iListBox->ConstructL(this, EAknListBoxSelectionList);
//	UpdateListBoxViewL();

	_LIT(KImgLocation,"\\system\\apps\\unlockme\\unlockme.mbm");
	iBitmap = iEikonEnv->CreateBitmapL(KImgLocation, EMbmUnlockmeSplashbg);
	iText = _L("Version 1.0");

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

CAboutContainer::~CAboutContainer() 
	{
	if (iBitmap) delete iBitmap;
//	if (iEditor) delete iEditor;
	}
// -----------------------------------------------------------------------------
// CAboutContainer::CountComponentControls() const
// returns number of controls inside this container.
// -----------------------------------------------------------------------------
//
TInt CAboutContainer::CountComponentControls() const
    {
	TInt count(0);
//	if (iEditor) count++;
    return count;
    }

// -----------------------------------------------------------------------------
// CAboutContainer::ComponentControl() const
// returns pointer of controls inside this container
// -----------------------------------------------------------------------------
//
CCoeControl* CAboutContainer::ComponentControl( TInt aIndex ) const
    {
	 switch ( aIndex )
		{
//		case 0:
//			return iEditor;
		default:
			return NULL;
		}
    }


void CAboutContainer::SizeChanged()
{
	//
	// Set the screen area where the listbox will be displayed.
	// 
//    if(iEditor)
//		iEditor->SetRect(Rect());
}



void CAboutContainer::DrawText( const TDesC& text, int y, const CFont* font) const
	{
	TRect aBox = TRect(0, y, Rect().Width(), y+font->HeightInPixels()+5);

    CWindowGc& gc = SystemGc();
    gc.SetBrushStyle(CGraphicsContext::ENullBrush);
    gc.SetPenStyle(CGraphicsContext::ESolidPen);
	gc.UseFont(font);

	aBox.Move(1, 1);
	gc.SetPenColor(KRgbGray);
	gc.DrawText(text, aBox, font->AscentInPixels(), CGraphicsContext::ECenter);
	
	aBox.Move(-1, -1);
	gc.SetPenColor(KRgbDarkGray);
	gc.DrawText(text, aBox, font->AscentInPixels(), CGraphicsContext::ECenter);
	gc.DiscardFont();
	}


void CAboutContainer::Draw( const TRect& aRect ) const
    {
    CWindowGc& gc = SystemGc();
	if (iBitmap) 
	{
		gc.BitBlt(TPoint(0,0), iBitmap);
	}
    DrawText(_L("Author: Marco Bellino"), 11, iEikonEnv->LegendFont());
    DrawText(_L("m.bellino@symbian-toys.com"), 31, iEikonEnv->DenseFont());
    DrawText(_L("http://www.symbian-toys.com"), 51, iEikonEnv->DenseFont());
    DrawText(_L("All Rights Reserved 2006"), 71, iEikonEnv->DenseFont());

	DrawText(iText, Rect().Height()-14, iEikonEnv->LegendFont());
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

