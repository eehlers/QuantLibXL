/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Eric Ehlers
 Copyright (C) 2008 Plamen Neykov

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

#ifndef qlxl_convert_timeseries_hpp
#define qlxl_convert_timeseries_hpp

#include <rp/conversions/convert.hpp>
#include <ql/types.hpp>
#include <map>

namespace QuantLib {
    class Date;
    class Period;
    class Quote;
    template <class T> class Handle;

    template<class T, class Container>
    class TimeSeries;

    typedef TimeSeries<QuantLib::Real, std::map<QuantLib::Date, QuantLib::Real> > TimeSeriesDef;
};

namespace reposit {

    class ConvertOper;

    template<> QuantLib::Date convert<QuantLib::Date, ConvertOper>(const ConvertOper& c);

    template<> QuantLib::Size convert<QuantLib::Size, ConvertOper>(const ConvertOper& p);

    template<>
    QuantLib::Period convert<QuantLib::Period, ConvertOper>(const ConvertOper& p);

    template<>
    QuantLib::Handle<QuantLib::Quote> convert<QuantLib::Handle<QuantLib::Quote>, ConvertOper>(const ConvertOper& c);

    template<>
    boost::shared_ptr<QuantLib::Quote> convert<boost::shared_ptr<QuantLib::Quote>, ConvertOper>(const ConvertOper& c);

    template<> QuantLib::TimeSeriesDef convert<QuantLib::TimeSeriesDef, ConvertOper>(const ConvertOper& c);
}

#endif
