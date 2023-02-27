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

            Log(std::string t_logDirectory){
                
                if(!std::filesystem::exists(t_logDirectory)){
                    std::filesystem::create_directory(t_logDirectory);
                }

                time_t m_curr_time;
                tm * m_curr_tm;

                time(&m_curr_time);
                m_curr_tm = localtime(&m_curr_time);

                char* m_timestamp;
                std::strftime(m_timestamp,50,"%H-%M-%S_%d-%m-%Y",m_curr_tm);

                std::string m_timestampStr(m_timestamp);
                std::string m_fileName = m_timestampStr+".log";

                this->m_filePath = t_logDirectory+"/"+m_fileName;
                this->m_fileStream.open(this->m_filePath);
            }

            void write(std::string t_msg, SeverityLevel t_lev, std::source_location t_location){
                time_t m_curr_time;
                tm * m_curr_tm;

                time(&m_curr_time);
                m_curr_tm = localtime(&m_curr_time);

                char* m_timestamp;
                std::strftime(m_timestamp,50,"%H:%M:%S",m_curr_tm);

                std::string timestampStr(m_timestamp);

                switch(t_lev){
                    case ll::SeverityLevel::INFO:
                        this->m_fileStream << "[" << timestampStr << "] [INFO] : " << t_msg << std::endl;
                    break;
                    case ll::SeverityLevel::WARNING:
                        this->m_fileStream << "[" << timestampStr << "] [WARN] " << t_location.file_name() << "(" << t_location.line() << ":" << t_location.column() << ") `" << t_location.function_name() << "` : " << t_msg << std::endl;
                    break;
                    case ll::SeverityLevel::ERROR:
                        this->m_fileStream << "[" << timestampStr << "] [ERROR] " << t_location.file_name() << "(" << t_location.line() << ":" << t_location.column() << ") `" << t_location.function_name() << "` : " << t_msg << std::endl;
                    break;
                }
                this->m_fileStream.flush();
            }

            void write(std::string t_msg, SeverityLevel t_lev, std::string t_code, std::source_location t_location){
                time_t m_curr_time;
                tm * m_curr_tm;

                time(&m_curr_time);
                m_curr_tm = localtime(&m_curr_time);

                char* m_timestamp;
                std::strftime(m_timestamp,50,"%H:%M:%S",m_curr_tm);

                std::string timestampStr(m_timestamp);

                switch(t_lev){
                    case ll::SeverityLevel::INFO:
                        this->m_fileStream << "[" << timestampStr << "] [INFO] : " << t_msg << std::endl;
                    break;
                    case ll::SeverityLevel::WARNING:
                        this->m_fileStream << "[" << timestampStr << "] [WARN] [code: "<< t_code << "] " << t_location.file_name() << "(" << t_location.line() << ":" << t_location.column() << ") `" << t_location.function_name() << "` : " << t_msg << std::endl;
                    break;
                    case ll::SeverityLevel::ERROR:
                        this->m_fileStream << "[" << timestampStr << "] [ERROR] [code: "<< t_code << "] " << t_location.file_name() << "(" << t_location.line() << ":" << t_location.column() << ") `" << t_location.function_name() << "` : " << t_msg << std::endl;
                    break;
                }
                this->m_fileStream.flush();
            }
        
            ~Log(){
                this->m_fileStream.close();
            }

            
    };
}
