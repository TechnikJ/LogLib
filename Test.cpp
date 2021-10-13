#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log();

    log.Initialize("Log");
    log.WriteString("Hi");
    
    return 1;
}