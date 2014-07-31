
#include "convert2.hpp"
#include "qlo/conversions/cnv_tmpl.hpp"

namespace ObjectHandler {

    template<> 
    QuantLib::Date convert2<QuantLib::Date, ConvertOper>(const ConvertOper& c) {
        return convertDate(c);
    }
}

