
#include <qlxl/conversions/convert2.hpp>
#include <qlo/conversions/cnv_tmpl.hpp>

template<> 
QuantLib::Date ObjectHandler::convert2<QuantLib::Date, ObjectHandler::ConvertOper>(const ConvertOper& c) {
    return convertDate(c);
}

template<>
QuantLib::Period ObjectHandler::convert2<QuantLib::Period, ObjectHandler::ConvertOper>(const ConvertOper& c) {
    return convertPeriod(c);
}

