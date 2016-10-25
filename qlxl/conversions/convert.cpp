
/*
 Copyright (C) 2006 Eric Ehlers

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

#include <rp/reposit.hpp>
#include <rpxl/convert_oper.hpp>
#include <qlxl/conversions/varianttoquotehandle.hpp>
#include <qlxl/conversions/varianttodate.hpp>
#include <qlxl/conversions/varianttoquote.hpp>
#include <qlxl/conversions/varianttoperiod.hpp>
#include <qlxl/conversions/varianttosize.hpp>
#include <qlxl/conversions/varianttotimeseries.hpp>
#include <qlo/conversions/convert_tmpl.hpp>

namespace reposit {

    template<> 
    QuantLib::Date convert<QuantLib::Date, ConvertOper>(const ConvertOper& c) {
        return convertDate(c);
    }

    //template<>
    //boost::shared_ptr<QuantLib::Quote> convert<boost::shared_ptr<QuantLib::Quote>, ConvertOper>(const ConvertOper& c) {
    //    return convertQuote(c);
    //}

    template<> 
    QuantLib::Period convert<QuantLib::Period, ConvertOper>(const ConvertOper& c) {
        return convertPeriod(c);
    }
    
    //template<> 
    //QuantLib::Size convert<QuantLib::Size, ConvertOper>(const ConvertOper& p) {
    //    return convertSize(p); 
    //}

    //template<>
    //QuantLib::Handle<QuantLib::Quote> convert<QuantLib::Handle<QuantLib::Quote>, ConvertOper>(const ConvertOper& c) {
    //    return convertQuoteHandle(c);
    //}

    //template<> 
    //QuantLib::TimeSeriesDef convert<QuantLib::TimeSeriesDef, ConvertOper>(const ConvertOper& c) {
    //    return convertTimeSeriesDef(c);
    //}
}
