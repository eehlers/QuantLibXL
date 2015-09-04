
/* 
 Copyright (C) 2005, 2006, 2007, 2008, 2014 Eric Ehlers

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <rpxl/repositxl.hpp>
//#include <qlo/qladdindefines.hpp>
#include <qlo/serialization/serializationfactory.hpp>
#include <qlo/init.hpp>
#include <qlxl/register/register_all.hpp>

/* Use BOOST_MSVC instead of _MSC_VER since some other vendors
   (Metrowerks, for example) also #define _MSC_VER
*/
#include <rp/rpdefines.hpp>
#if defined BOOST_MSVC       // Microsoft Visual C++
#  define BOOST_LIB_DIAGNOSTIC
#  include <rp/auto_link.hpp>
#  include <qlo/auto_link.hpp>
#  include <ql/auto_link.hpp>
#  if defined(XLL_STATIC)
     #include <rpxl/register/register_all.hpp>
     #include <rpxl/functions/export.hpp>
     #pragma message("XLL_STATIC is defined")
#  elif defined(XLL_IMPORTS)
     #include <xlsdk/auto_link.hpp>
     #pragma message("XLL_IMPORTS is defined")
#  endif
#  undef BOOST_LIB_DIAGNOSTIC
#endif

#if defined COMPILING_XLL_DYNAMIC
#   pragma message("COMPILING_XLL_DYNAMIC is defined")
#else
#   pragma message("COMPILING_XLL_DYNAMIC is NOT defined")
#endif

void init() {

	#ifdef XLL_STATIC
	// Instantiate the reposit Repository
	static reposit::RepositoryXL repositoryXL;
	// Instantiate the Enumerated Type Registry
	static reposit::EnumTypeRegistry enumTypeRegistry;
	// Instantiate the Enumerated Class Registry
	static reposit::EnumClassRegistry enumClassRegistry;
	// Instantiate the Enumerated Pair Registry
	static reposit::EnumPairRegistry enumPairRegistry;
	#endif
    // Instantiate the Processor Factory
    static reposit::ProcessorFactory processorFactory;
	// Instantiate the Serialization Factory
	static QuantLibAddin::SerializationFactory factory;
    // Initialize the Enumeration Registry
    //QuantLibAddin::initializeAddin();
}

DLLEXPORT void xlAutoFree(XLOPER *px) {

    freeOper(px);
}

DLLEXPORT XLOPER *xlAddInManagerInfo(XLOPER *xlAction) {

	init();

    XLOPER xlReturn;
    static XLOPER xlLongName;

    // Coerce the argument XLOPER to an integer.
    Excel(xlCoerce, &xlReturn, 2, xlAction, TempInt(xltypeInt));

    // The only valid argument value is 1. In this case we return the
    // long name for the XLL. Any other value should result in the
    // return of a #VALUE! error.
    if (1 == xlReturn.val.w) {
        reposit::scalarToOper(std::string("QuantLibXL " /*QLADDIN_VERSION*/), xlLongName);
    } else {
        xlLongName.xltype = xltypeErr;
        xlLongName.val.err = xlerrValue;
    }

    return &xlLongName;
}

DLLEXPORT int xlAutoOpen() {

	init();

    XLOPER xDll;

    try {

        Excel(xlGetName, &xDll, 0);

#ifdef XLL_STATIC
        // Initialize configuration info
        reposit::Configuration::instance().init();

        // Initialize reposit functions
        registerOhFunctions(xDll);
#endif
        // Initialize QuantLib functions
        registerFunctions(xDll);

        // Initialize the Enumeration Registry
        QuantLibAddin::initializeAddin();

        Excel(xlFree, 0, 1, &xDll);

        return 1;

    } catch (const std::exception &e) {

        std::ostringstream err;
        err << "Error loading QuantLibXL: " << e.what();
        Excel(xlcAlert, 0, 1, TempStrStl(err.str()));
        Excel(xlFree, 0, 1, &xDll);
        return 0;

    } catch (...) {

        Excel(xlFree, 0, 1, &xDll);
        return 0;

    }
}

DLLEXPORT int xlAutoClose() {

    static XLOPER xDll;

    try {

        Excel(xlGetName, &xDll, 0);

#ifdef XLL_STATIC
        // Unregister reposit functions
        unregisterOhFunctions(xDll);
#endif

        // Unregister QuantLib functions
        unregisterFunctions(xDll);

        // Clear the Enumeration Registry
        QuantLibAddin::closeAddin();

#ifdef XLL_STATIC
        reposit::RepositoryXL::instance().clear();
#endif

        Excel(xlFree, 0, 1, &xDll);

        return 1;

    } catch (const std::exception &e) {

        Excel(xlFree, 0, 1, &xDll);
        std::ostringstream err;
        err << "Error unloading QuantLibXL: " << e.what();
        Excel(xlcAlert, 0, 1, TempStrStl(err.str()));
        return 0;

    } catch (...) {

        Excel(xlFree, 0, 1, &xDll);
        return 0;

    }
}

