
#include "Storage.h"
#include <e32uid.h>
#include <f32file.h>
#include <s32stor.h>
#include <s32file.h>
#include <bautils.h>


// INCLUDE FILES
/*#include <e32std.h>
#include <avkon.hrh>
#include <aknnavi.h>
#include <akntitle.h> 
#include <eikapp.h>		// Application
#include <AknQueryDialog.h> */



CStorage* CStorage::NewL(RFs& fsSession, const TDesC& drive) 
	{
    CStorage* self = new ( ELeave ) CStorage();
    CleanupStack::PushL( self );
    self->ConstructL(fsSession, drive);
    CleanupStack::Pop( self );
    return self;
	}


void CStorage::ConstructL(RFs& fsSession, const TDesC& drive) 
	{
	iFs = &fsSession;
	iDatFile = drive;
#ifdef  __WINS__
	iDatFile = _L("c:");
#endif
	iDatFile.Append(KFileSettings);
	iSettings.Default();
	}


void CStorage::SaveSettingsL()
	{	
	iFs->Delete( iDatFile );
	iFs->MkDirAll( iDatFile );
	CDictionaryStore* dictstore = CDictionaryFileStore::OpenLC (*iFs, iDatFile, TUid::Uid(0x1020dc97) );

	RDictionaryWriteStream out;
	out.AssignLC(*dictstore, TUid::Uid(0x1020DC9C));
//	out.AssignLC(*dictstore, TUid::Uid(0x00000001));

	out << iSettings;

	out.CommitL();            // Commit changes to the stream
	dictstore->CommitL();

	out.Close();	
	CleanupStack::PopAndDestroy(2); // out dictstore
	}


void CStorage::ResetSettingsL()
	{
	iSettings.Default();
	SaveSettingsL();
	}


/// Legge le impostazioni, restituisce un intero != 0 se le impostaz. non sono presenti
TInt CStorage::LoadSettingsL()
	{	
	iSettings.Default();
	TEntry entry;
	
	TInt ris = iFs->Entry(iDatFile, entry);
	if (ris != KErrNone) 
	{
		return ris;
	}

	CDictionaryStore* dictstore = CDictionaryFileStore::OpenLC (*iFs, iDatFile ,TUid::Uid(0x1020dc97) );

	RDictionaryReadStream in;
	in.OpenLC(*dictstore,TUid::Uid(0x1020DC9C));
//	in.OpenLC(*dictstore,TUid::Uid(0x00000001));

	in >> iSettings;

	in.Close();	
	CleanupStack::PopAndDestroy(2); // in dictstore
	return ris;
	}	





/**/
