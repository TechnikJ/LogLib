#include "include/LogLib/LogLib.hpp"

int main(){

    ll::Log log = ll::Log();

    log.init("Log");
    log.write("Info... just info",ll::SeverityLevel::INFO);
    log.write("ErrorWithCode",ll::SeverityLevel::ERROR,"0x02304780");
    log.write("WarningWithoutCode",ll::SeverityLevel::WARNING);

    return 1;
}