#ifndef LOG_LIB_HPP_
#define LOG_LIB_HPP_

#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>

namespace ll{

    std::ofstream FileStream;
    std::string filePath;

    static void Initialize(std::string LogDirectory){
        
        if(!std::filesystem::exists(LogDirectory)){
            std::filesystem::create_directory(LogDirectory);
        }

        time_t curr_time;
	    tm * curr_tm;

        time(&curr_time);
	    curr_tm = localtime(&curr_time);

        char* timestamp;
        std::strftime(timestamp,50,"%H:%M:%s_%d-%m-%Y",curr_tm);

        std::string timestampStr(timestamp);
        std::string FileName = timestampStr+".log";

        filePath = LogDirectory+"/"+FileName;

        FileStream.open(filePath);
    }

    static void LogString(std::string ctx){
        time_t curr_time;
	    tm * curr_tm;

        time(&curr_time);
	    curr_tm = localtime(&curr_time);

        char* timestamp;
        std::strftime(timestamp,50,"%H:%M:%s",curr_tm);

        std::string timestampStr(timestamp);

        std::string logContent = "["+timestampStr+"]"+": "+ctx;

        FileStream << logContent;
        FileStream.close();
        FileStream.open(filePath);
    }


}