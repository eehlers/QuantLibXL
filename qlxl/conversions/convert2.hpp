
#ifndef addinxll_convert2_hpp
#define addinxll_convert2_hpp

#include <boost/lexical_cast.hpp>
#include <ohxl/convert_oper.hpp>
#include <ql/time/date.hpp>
#include <ql/time/period.hpp>

namespace ObjectHandler {

    template<> 
    QuantLib::Date convert2<QuantLib::Date, ConvertOper>(const ConvertOper& c);

    template<>
    QuantLib::Period convert2<QuantLib::Period, ConvertOper>(const ConvertOper& p);
}

#endif


