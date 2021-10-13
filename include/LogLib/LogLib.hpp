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

        void Initialize(std::string LogDirectory){
            
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

        void WriteString(std::string ctx){
            std::cout << this->filePath << std::endl;
            
            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H:%M:%s",curr_tm);

            std::string timestampStr(timestamp);

            std::string logContent = "["+timestampStr+"]"+": "+ctx;

            //this->FileStream << logContent;
            this->FileStream << ctx << std::endl;
            this->FileStream.flush();
        }
};
