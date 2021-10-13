#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log();

    log.Initialize("Log");
    log.WriteString("Hi");
    log.WriteString("Ho");

    return 1;
}