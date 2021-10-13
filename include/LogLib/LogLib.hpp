#ifndef LOG_LIB_HPP_
#define LOG_LIB_HPP_

#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>

namespace ll{

    std::ofstream FileStream;

    static void Initialize(std::string LogDirectory){
        
        if(!std::filesystem::exists(LogDirectory)){
            std::filesystem::create_directory(LogDirectory);
        }

        time_t curr_time;
	    tm * curr_tm;

        time(&curr_time);
	    curr_tm = localtime(&curr_time);

        char* timestamp;
        std::strftime(timestamp,50,"%d-%m-%Y",curr_tm);

        std::string timestampStr(timestamp);
        std::string FileName = timestampStr+".log";

        std::cout << FileName << std::endl;

        std::string filePath = LogDirectory+"/"+FileName;

        FileStream.open(filePath);
    }

    static void LogString(std::string ctx){

    }


}