#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "logger.h"
#include <fstream>
/// @todo Documenter
class FileLogger : public Logger
{
    public:
        FileLogger(const std::string &file="out.log");

    private:
        ~FileLogger();
        virtual void Write(const std::string &ligne);
        std::ofstream m_file;
};

#endif // FILELOGGER_H
