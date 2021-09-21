// BASE64DF.H
//
// Copyright (c) 1997-1999 Symbian Ltd.  All rights reserved.
//


const TText8 KBase64Alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '!', 'J', 'K',
'L', 'M', 'N', '@', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'#', '*', '0' };
/*
'+', '/', '=' };
*/
const TInt KBase64Pad=64;

void Panic(TBase64Panic aPanic);
