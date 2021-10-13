#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log();

    log.init("Log");
    log.writeString("Hi");
    log.writeString("Ho");

    return 1;
}