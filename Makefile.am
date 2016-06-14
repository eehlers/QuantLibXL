
SUBDIRS = \
    Docs

EXTRA_DIST = \
    Authors.txt \
    Contributors.txt \
    LICENSE.TXT \
    NEWS.txt \
    QuantLibAllDynamic_vc8.sln \
    QuantLibAllDynamic_vc9.sln \
    QuantLibXL_basic_vc8.sln \
    QuantLibXL_basic_vc9.sln \
    QuantLibXL-bin.nsi \
    QuantLibXL_full_vc8.sln \
    QuantLibXL_full_vc9.sln \
    QuantLibXL.nsi \
    QuantLibXL-src.nsi \
    README.txt \
    todo.txt

.PHONY: docs docs-clean
docs:
	$(MAKE) -C Docs docs-html
docs-clean:
	$(MAKE) -C Docs docs-clean

