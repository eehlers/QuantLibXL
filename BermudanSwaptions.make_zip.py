
import sys
import os
import shutil
import datetime
import glob
import zipfile
import argparse
import re

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
        print sourcePath
        if targetPath is None:
            targetPath = self.root + sourcePath
        else:
            targetPath = self.root + targetPath
        self.zipFile.write(sourcePath, targetPath)

    def zipGlob(self, path, excludeFiles = None):
        for fileName in glob.glob(path):
            if excludeFiles is not None:
                for r in excludeFiles:
                    if r.match(fileName):
                        continue
            print fileName
            self.zip(fileName)

def prompt_exit(msg='', status=0):
    if msg:
        print msg
    if sys.platform == 'win32':
        raw_input('press any key to exit')
    sys.exit(status)

zipFile = ZipFile("zip\\BermudanSwaptions.zip", "BermudanSwaptions\\")
zipFile.zip("BermudanSwaptions.xlam")
zipFile.zip("BermudanSwaptions.bat")
zipFile.zip("BermudanSwaptions.README.TXT", "README.TXT")
zipFile.zip("xll\\QuantLibXL-vc90-mt-s-1_7_0.xll")
zipFile.zip("BermudanSwaptions\\GBP_Market_And_Trades.xlsx")
zipFile.zip("BermudanSwaptions\\README.TXT")

raw_input('press any key to exit')

