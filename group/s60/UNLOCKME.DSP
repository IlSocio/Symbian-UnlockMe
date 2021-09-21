# Microsoft Developer Studio Project File - Name="UNLOCKME" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=UNLOCKME - Win32 Uni Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "UNLOCKME.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "UNLOCKME.mak" CFG="UNLOCKME - Win32 Uni Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "UNLOCKME - Win32 Uni Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "UNLOCKME - Win32 Uni Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "UNLOCKME - Win32 Uni Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Win32_U0"
# PROP BASE Intermediate_Dir ".\Win32_U0"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB"
# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS\UDEB"
# ADD CPP /nologo /Zp4 /GF /MDd /W4 /Zi /Od /X /I "\ONLINE\UNLOCKME\DATA" /I "\ONLINE\UNLOCKME\INC" /I "\ONLINE\UNLOCKME\INC\S60" /I "\Symbian\7.0s\Series60_v20\EPOC32\INCLUDE" /D "__SYMBIAN32__" /D "__VC32__" /D "__WINS__" /D "__DLL__" /D "_DEBUG" /D "_UNICODE" /FR /Fd"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.PDB" /c
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\EDLL.LIB" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\flogger.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\mediaclientaudio.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\cntmodel.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\euser.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\apparc.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\cone.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikcore.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikcoctl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\avkon.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikdlg.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikctl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\msgs.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\smcm.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\gsmu.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\mtur.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\commonengine.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\fbscli.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\pbkview.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\pbkeng.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etext.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etel.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\efsrv.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etelmm.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\commdb.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\estor.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\bafl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\egul.lib" "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS\UDEB\UNLOCKME.exp" /nologo /entry:"_E32Dll" /subsystem:windows /dll /pdb:"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.pdb" /debug /machine:IX86 /nodefaultlib /include:"?_E32Dll@@YGHPAXI0@Z" /out:"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.APP" /WARN:3
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
SOURCE=$(InputPath)
PreLink_Cmds=echo Doing first-stage link by name\
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" PRELINKUDEB\
	if errorlevel 1 nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" STOPLINKUDEB 
PostBuild_Cmds=nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" POSTBUILDUDEB
# End Special Build Tool

!ELSEIF  "$(CFG)" == "UNLOCKME - Win32 Uni Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Win32_Un"
# PROP BASE Intermediate_Dir ".\Win32_Un"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL"
# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS\UREL"
# ADD CPP /nologo /Zp4 /GF /MD /W4 /O1 /Op /X /I "\ONLINE\UNLOCKME\DATA" /I "\ONLINE\UNLOCKME\INC" /I "\ONLINE\UNLOCKME\INC\S60" /I "\Symbian\7.0s\Series60_v20\EPOC32\INCLUDE" /D "__SYMBIAN32__" /D "__VC32__" /D "__WINS__" /D "__DLL__" /D "NDEBUG" /D "_UNICODE" /c
# ADD MTL /nologo /mktyplib203 /D /win32
# ADD BASE RSC /l 0x809
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\EDLL.LIB" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\flogger.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\mediaclientaudio.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\cntmodel.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\euser.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\apparc.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\cone.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikcore.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikcoctl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\avkon.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikdlg.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\eikctl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\msgs.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\smcm.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\gsmu.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\mtur.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\commonengine.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\fbscli.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\pbkview.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\pbkeng.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etext.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etel.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\efsrv.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\etelmm.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\commdb.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\estor.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\bafl.lib" "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\egul.lib" "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS\UREL\UNLOCKME.exp" /nologo /entry:"_E32Dll" /subsystem:windows /dll /machine:IX86 /nodefaultlib /include:"?_E32Dll@@YGHPAXI0@Z" /out:"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.APP" /WARN:3
# Begin Special Build Tool
SOURCE=$(InputPath)
PreLink_Cmds=echo Doing first-stage link by name\
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" PRELINKUREL\
	if errorlevel 1 nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" STOPLINKUREL 
PostBuild_Cmds=nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE" POSTBUILDUREL
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "UNLOCKME - Win32 Uni Debug"
# Name "UNLOCKME - Win32 Uni Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\DATA\S60\Unlockme.rss
USERDEP__UNLOCKME="\ONLINE\UNLOCKME\DATA\UNLOCKME.L01"\
 "\ONLINE\UNLOCKME\DATA\UNLOCKME.LOC" "\ONLINE\UNLOCKME\INC\S60\UNLOCKME.HRH"

!IF  "$(CFG)" == "UNLOCKME - Win32 Uni Debug"

# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS"
# Begin Custom Build - Building resources from Unlockme.rss
InputPath=\ONLINE\UNLOCKME\DATA\S60\Unlockme.rss

BuildCmds= \
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE"\
  "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.r"

"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.r01" : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "UNLOCKME - Win32 Uni Release"

# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS"
# Begin Custom Build - Building resources from Unlockme.rss
InputPath=\ONLINE\UNLOCKME\DATA\S60\Unlockme.rss

BuildCmds= \
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE"\
  "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.r"

"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME.r01" : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\DATA\S60\Unlockme_caption.rss
USERDEP__UNLOCKME_CAPTION="\ONLINE\UNLOCKME\DATA\UNLOCKME.L01"\
 "\ONLINE\UNLOCKME\DATA\UNLOCKME.LOC"

!IF  "$(CFG)" == "UNLOCKME - Win32 Uni Debug"

# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS"
# Begin Custom Build - Building resources from Unlockme_caption.rss
InputPath=\ONLINE\UNLOCKME\DATA\S60\Unlockme_caption.rss

BuildCmds= \
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE"\
  "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME_CAPTION.r"

"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UDEB\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME_CAPTION.r01" : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "UNLOCKME - Win32 Uni Release"

# PROP Intermediate_Dir "\Symbian\7.0s\Series60_v20\EPOC32\BUILD\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME\WINS"
# Begin Custom Build - Building resources from Unlockme_caption.rss
InputPath=\ONLINE\UNLOCKME\DATA\S60\Unlockme_caption.rss

BuildCmds= \
	nmake -nologo -f "\ONLINE\UNLOCKME\GROUP\S60\UNLOCKME.SUP.MAKE"\
  "\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME_CAPTION.r"

"\Symbian\7.0s\Series60_v20\EPOC32\RELEASE\WINS\UREL\Z\SYSTEM\APPS\UNLOCKME\UNLOCKME_CAPTION.r01" : $(SOURCE) "$(INTDIR)"\
 "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\GROUP\S60\Unlockme.uid.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\Base64.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\Phone.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\Storage.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\Timeouttimer.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Aboutcontainer.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Aboutview.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Creditscontainer.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Creditsview.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Splashcontainer.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Splashview.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Unlockme.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Unlockmeapplication.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Unlockmeappui.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\SRC\S60\Unlockmedocument.cpp
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\GROUP\S60\Unlockme.mmp
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Unlockmeappui.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Splashview.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Splashcontainer.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Aboutcontainer.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Base64.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Unlockme.pan
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Creditscontainer.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Unlockme.hrh
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Timeouttimer.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Base64df.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Storage.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Timeoutnotifier.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Aboutview.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\Phone.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Creditsview.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Unlockmedocument.h
# End Source File
# Begin Source File

SOURCE=\ONLINE\UNLOCKME\INC\S60\Unlockmeapplication.h
# End Source File
# End Group
# End Target
# End Project
