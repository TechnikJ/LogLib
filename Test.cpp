#include "include/LogLib/LogLib.hpp"

int main(){

    Log log = Log("Log");
    log.WriteString("Hi");
    log.WriteString("Ho");

    return 1;
}
