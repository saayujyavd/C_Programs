cls

cl.exe /c /EHsc window.c calculator.c cnvrt.c getop.c dlgbox.c

rc.exe template.rc

link.exe user32.lib /DLL dlgbox.obj /DEF:dlgbox.def /OUT:dlgbox.dll
link.exe window.obj template.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS

del *.obj
del *.exp
del *.lib
