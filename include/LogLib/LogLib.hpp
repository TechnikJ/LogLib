#ifndef LOG_LIB_HPP_
#define LOG_LIB_HPP_

#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <source_location>

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

        void  writeInfo(std::string msg){
            
            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

            std::string timestampStr(timestamp);

            std::string logContent = "["+timestampStr+"] [INFO]"+": "+msg;

            this->FileStream << logContent << std::endl;
            this->FileStream.flush();
        }

        void writeError(std::string msg, std::string errorCode, const std::source_location location = std::source_location::current()){

            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

            std::string timestampStr(timestamp);

            this->FileStream << "[" << timestampStr+"] [ERROR] [code: "<< errorCode << "] " << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << "` : " << msg << std::endl;
            this->FileStream.flush();
        }

        void writeWarning(std::string msg, std::string warningCode, const std::source_location location = std::source_location::current()){

            time_t curr_time;
            tm * curr_tm;

            time(&curr_time);
            curr_tm = localtime(&curr_time);

            char* timestamp;
            std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

            std::string timestampStr(timestamp);

            this->FileStream << "[" << timestampStr+"] [WARN] [code: "<< warningCode << "] " << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << "` : " << msg << std::endl;
            this->FileStream.flush();
        }
};
