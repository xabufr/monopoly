#include "logger.h"
#include <cstdarg>
#include <cstdio>
#include <sstream>

Logger *Logger::m_logger=NULL;
const char Logger::endl='\n';

void Logger::Destroy()
{
    if(m_logger!=0)
        delete m_logger;
    m_logger=NULL;
}

void Logger::Out(std::string ligne)
{
    Assert(m_logger!=NULL);
    m_logger->Write(ligne);
}
void Logger::Out(const char *ligne, ...)
{
    Assert(m_logger!=NULL);

    char buffer[1024];
    va_list Params;
    va_start(Params, ligne);
    vsprintf(buffer,ligne,Params);
    va_end(Params);

    m_logger->Write(buffer);
}
void Logger::SetLogger(Logger *log)
{
    Destroy();
    m_logger=log;
}
Logger& Logger::operator <<(const char* mes)
{
    Assert(m_logger!=NULL);

    m_logger->Write(std::string(mes));
    return Log();
}
Logger& Logger::Log()
{
    return *m_logger;
}

Logger::~Logger()
{

}
