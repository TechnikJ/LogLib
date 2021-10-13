#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log();

    log.init("Log");
    log.writeInfo("Test");
    log.writeWarning("Test","303");
    log.writeError("Test","404");
    return 1;
}