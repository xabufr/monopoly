#include "filelogger.h"

FileLogger::FileLogger(const std::string &file)
{
    m_file.open(file.c_str());
}

FileLogger::~FileLogger()
{
    m_file.close();
}
void FileLogger::Write(const std::string &ligne)
{
    m_file << ligne;
    m_file.flush();
}
