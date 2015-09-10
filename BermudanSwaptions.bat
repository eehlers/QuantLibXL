
@REM Use this bat file to ensure that the demo runs in a new Excel instance.

@REM read only
@REM START "EXCEL" "EXCEL.EXE" /e /r BermudanSwaptions.xlam

@REM read write
START "EXCEL" "EXCEL.EXE" /e BermudanSwaptions.xlam

