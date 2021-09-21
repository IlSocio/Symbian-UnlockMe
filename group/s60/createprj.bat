REM devices -setdefault @s60_2nd
call bldmake bldfiles
call abld reallyclean
call makmake UnlockMe.mmp vc6
pause
