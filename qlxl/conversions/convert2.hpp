
#ifndef addincpp_convert2_hpp
#define addincpp_convert2_hpp

#include <boost/lexical_cast.hpp>
#include <ohxl/convert_oper.hpp>
#include <ql/time/date.hpp>

namespace ObjectHandler {

    template<> 
    QuantLib::Date convert2<QuantLib::Date, ConvertOper>(const ConvertOper& c);
}

#endif


