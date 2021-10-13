#ifndef LOG_LIB_HPP_
#define LOG_LIB_HPP_

#endif

#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>
#include <source_location>
namespace ll{
    enum class SeverityLevel: uint8_t{
        INFO,
        WARNING,
        ERROR
    };
    class Log {
            std::ofstream m_fileStream;
            std::string m_filePath;
        public:

            Log(){}
            ~Log(){
                this->m_fileStream.close();
            }

            void init(std::string t_logDirectory){
                
                if(!std::filesystem::exists(t_logDirectory)){
                    std::filesystem::create_directory(t_logDirectory);
                }

                time_t m_curr_time;
                tm * m_curr_tm;

                time(&m_curr_time);
                m_curr_tm = localtime(&m_curr_time);

                char* timestamp;
                std::strftime(timestamp,50,"%H-%M-%S_%d-%m-%Y",m_curr_tm);

                std::string m_timestampStr(timestamp);
                std::string m_fileName = m_timestampStr+".log";

                this->m_filePath = t_logDirectory+"/"+m_fileName;
                this->m_fileStream.open(this->m_filePath);
            }

            void writeInfo(std::string msg){
                
                time_t curr_time;
                tm * curr_tm;

                time(&curr_time);
                curr_tm = localtime(&curr_time);

                char* timestamp;
                std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

                std::string timestampStr(timestamp);

                std::string logContent = "["+timestampStr+"] [INFO]"+": "+msg;

                this->m_fileStream << logContent << std::endl;
                this->m_fileStream.flush();
            }

            void writeError(std::string msg, std::string errorCode, const std::source_location location = std::source_location::current()){

                time_t curr_time;
                tm * curr_tm;

                time(&curr_time);
                curr_tm = localtime(&curr_time);

                char* timestamp;
                std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

                std::string timestampStr(timestamp);

                this->m_fileStream << "[" << timestampStr+"] [ERROR] [code: "<< errorCode << "] " << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << "` : " << msg << std::endl;
                this->m_fileStream.flush();
            }

            void writeWarning(std::string msg, std::string warningCode, const std::source_location location = std::source_location::current()){

                time_t curr_time;
                tm * curr_tm;

                time(&curr_time);
                curr_tm = localtime(&curr_time);

                char* timestamp;
                std::strftime(timestamp,50,"%H:%M:%S",curr_tm);

                std::string timestampStr(timestamp);

                this->m_fileStream << "[" << timestampStr+"] [WARN] [code: "<< warningCode << "] " << location.file_name() << "(" << location.line() << ":" << location.column() << ") `" << location.function_name() << "` : " << msg << std::endl;
                this->m_fileStream.flush();
            }
    };
}