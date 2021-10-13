#include "include/LogLib/LogLib.hpp"

int main(){
    ll::Initialize("Log");

    ll::LogString("LogTest");
    ll::LogString("Just A Test"); 
}