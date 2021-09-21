// BASE64.H
//
// Copyright (c) 1997-1999 Symbian Ltd.  All rights reserved.
//

#if !defined(__e32base_h__)
#include "e32base.h"
#endif

const TInt KErrInvalidSource=(-1);
const TUint8 KErrInvalidCharacter=65;

enum TBase64Panic
	{
	EBase64Overflow
	};

class CBase64CodecBase : public CBase
	{
public:
	void Reset();
	TInt Encode(const TDesC& aSource, TDes& aResult) const;
	TInt Decode(const TDesC& aSource, TDes& aResult);
	TUint Base64Char(TText aChar) const;
private:
	TUint iQuart[4];
	TInt iQuartCount;
	};

