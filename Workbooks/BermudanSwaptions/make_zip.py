
import sys
import os
import shutil
import datetime
import glob
import zipfile
import argparse
import re
import traceback

QLXL = "QuantLibXL"
VERSION = "1.7.0"
VERSION_ = "1_7_0"
VC_VERSION = "vc120"
QLXL_VERSION = QLXL + "-" + VERSION
ROOT_DIR = QLXL_VERSION + "\\"

class ZipFile:

    root = None
    zipFile = None

    def __init__(self, path, root):
        self.root = root
        self.zipFile = zipfile.ZipFile(path, "w", zipfile.ZIP_DEFLATED)

    def __del__(self):
        self.zipFile.close()

    def zip(self, sourcePath, targetPath = None):
        if targetPath is None:
            targetPath = self.root + sourcePath
        else:
            targetPath = self.root + targetPath
        self.zipFile.write(sourcePath, targetPath)
        print "Zipping file..." + targetPath

    def zipGlob(self, path, excludeFiles = None):
        for fileName in glob.glob(path):
            if excludeFiles is not None:
                for r in excludeFiles:
                    if r.match(fileName):
                        continue
            self.zip(fileName)

#def prompt_exit(msg='', status=0):
#    if msg:
#        print msg
#    if sys.platform == 'win32':
#        raw_input('press any key to exit')
#    sys.exit(status)

ERROR_WRAPPER='''
the script has encountered a fatal error.

>>>>>>>>>> BEGIN STACK TRACE >>>>>>>>>>

%(stack)s
<<<<<<<<<<  END STACK TRACE  <<<<<<<<<< 

gensrc error:
%(value)s

'''

def bs_excepthook(type, value, tb):
    """Implement a hook to be invoked when an exception is encountered."""

    # Format the stack trace.
    stack = ''.join(traceback.format_tb(tb))

    # Format the error message.
    message = ERROR_WRAPPER % {
        'stack' : stack,
        'value' : str(value) }

    # Write the error message to stdout.
    sys.stderr.write(message)
    raw_input('press any key to exit')

sys.excepthook = bs_excepthook

zipFile = ZipFile("zip\\BermudanSwaptions.zip", "BermudanSwaptions\\")
zipFile.zip("init.xlam")
zipFile.zip("zip\\init.INSTALLED.bat", "init.bat")
zipFile.zip("zip\\README.INSTALLED.TXT", "README.TXT")
zipFile.zip("..\\..\\xll\\QuantLibXL-vc90-mt-1_7_0.xll", "xll\\QuantLibXL-vc90-mt-1_7_0.xll")
zipFile.zip("xlsx\\GBP_Market_And_Trades.xlsx")

raw_input('press any key to exit')

