#ifndef LOG_LIB_HPP_
#define LOG_LIB_HPP_

#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>

class Log {

    private:
        std::ofstream FileStream;
        std::string filePath;
    public:

        Log(){}
        ~Log(){
            this->FileStream.close();
        }

        void init(std::string LogDirectory){
            
            if(!std::filesystem::exists(LogDirectory)){
                std::filesystem::create_directory(LogDirectory);
            }

            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H-%M-%S_%d-%m-%Y",curr_tm);

            std::string timestampStr(timestamp);
            std::string FileName = timestampStr+".log";

            this->filePath = LogDirectory+"/"+FileName;
            this->FileStream.open(this->filePath);
        }

        void  writeInfo(std::string ctx){
            
            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

            std::string timestampStr(timestamp);

            std::string logContent = "["+timestampStr+"] [INFO]"+": "+ctx;

            this->FileStream << logContent << std::endl;
            this->FileStream.flush();
        }
};
