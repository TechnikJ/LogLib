#include "include/LogLib/LogLib.hpp"
#include <source_location>

int main(){

    ll::Log log = ll::Log();

    log.init("Log");
    log.write("Info... just info",ll::SeverityLevel::INFO,std::source_location::current());
    log.write("ErrorWithCode",ll::SeverityLevel::ERROR,"0x02304780",std::source_location::current());
    log.write("WarningWithoutCode",ll::SeverityLevel::WARNING,std::source_location::current());

    return 1;
}