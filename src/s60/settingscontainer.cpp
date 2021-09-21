

// INCLUDE FILES
#include "SettingsContainer.h"
#include <AknLists.h>
#include <barsread.h>
#include <FlashSms.rsg>
#include <eikedwin.h>
//TODO proibire cut-paste

// -----------------------------------------------------------------------------
// CSettingsContainer::ConstructL()
// Symbian 2nd phase constructor can leave.
// -----------------------------------------------------------------------------
//
void CSettingsContainer::ConstructL( const TRect& aRect, TFlashSmsSettings& settings )
    {
    CreateWindowL();

	iSettings = &settings;

    TResourceReader reader;
    iCoeEnv->CreateResourceReaderLC( reader, R_SMS_EDITOR );
    iEdwin = new ( ELeave ) CEikEdwin;
    iEdwin->SetContainerWindowL( *this );
    iEdwin->ConstructFromResourceL( reader );
    CleanupStack::PopAndDestroy();  // Resource reader
    iEdwin->SetExtent( TPoint(0,0), aRect.Size() );
    iEdwin->SetFocus( ETrue );

/*	iEdwin->OverrideColorL(EColorControlText,  TRgb(100, 100, 100));
	iEdwin->OverrideColorL(EColorControlSurroundText,  TRgb(100, 100, 100));
	iEdwin->OverrideColorL(EColorControlHighlightText,  TRgb(100, 100, 100));
	iEdwin->OverrideColorL(EColorDialogText,  TRgb(100, 100, 100));
	iEdwin->OverrideColorL(EColorDialogTitle,  TRgb(100, 100, 100));
	iEdwin->OverrideColorL(EColorLabelText,  TRgb(100, 100, 100));*/
	
	CCharFormatLayer* FormatLayer=CEikonEnv::NewDefaultCharFormatLayerL();

	TCharFormat charFormat; 
	TCharFormatMask charFormatMask; 
	FormatLayer->Sense(charFormat, charFormatMask);

	charFormat.iFontPresentation.iTextColor=KRgbBlack;
	charFormatMask.SetAttrib(EAttColor);
	FormatLayer->SetL(charFormat, charFormatMask);

	iEdwin->SetCharFormatLayer(FormatLayer);

    SetRect( aRect );
    ActivateL();
	}



CSettingsContainer::~CSettingsContainer() 
	{
	if (iEdwin) 
		delete iEdwin;
	}
// -----------------------------------------------------------------------------
// CSettingsContainer::CountComponentControls() const
// returns number of controls inside this container.
// -----------------------------------------------------------------------------
//
TInt CSettingsContainer::CountComponentControls() const
    {
	TInt count(0);
	if (iEdwin) count++;
    return count;
    }


/*void CSettingsContainer::ShowFormL()
    {
    CAknExEditorDialog* dialog = new ( ELeave ) CAknExEditorDialog();
    dialog->ExecuteLD( R_AKNEXEDITOR_VIEW9_DIALOG );
    }*/


// -----------------------------------------------------------------------------
// CSettingsContainer::ComponentControl() const
// returns pointer of controls inside this container
// -----------------------------------------------------------------------------
//
CCoeControl* CSettingsContainer::ComponentControl( TInt aIndex ) const
    {
	 switch ( aIndex )
		{
		case 0:
			return iEdwin;
		default:
			return NULL;
		}
    }


void CSettingsContainer::SizeChanged()
{
	//
	// Set the screen area where the listbox will be displayed.
	// 
    /*if(iEdwin)
		iEdwin->SetRect(Rect());*/
}



TKeyResponse CSettingsContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType) 
	{
//    if ( aType != EEventKey )
//        return EKeyWasNotConsumed;

    if ( iEdwin )
        {
        if ( iEdwin->IsFocused() )
            {
            return iEdwin->OfferKeyEventL( aKeyEvent, aType );
            }
        }
	return EKeyWasNotConsumed;	
	}
// -----------------------------------------------------------------------------
// CSettingsContainer::Draw() const
// Draws the display
// -----------------------------------------------------------------------------
//
void CSettingsContainer::Draw( const TRect& aRect ) const
    {
    CWindowGc& gc = SystemGc();
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbBlack );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
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

