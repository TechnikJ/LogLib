#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log();

    log.init("Log");
    log.writeInfo("Hi");
    log.writeInfo("Ho");
    log.writeError("Test","1x002");
    return 1;
}