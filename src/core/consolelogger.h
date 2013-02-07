#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "logger.h"
#include <iostream>
/// @todo Documenter

class ConsoleLogger : public Logger
{
    public:
    protected:
    private:
        virtual void Write(const std::string & message);
};

#endif // CONSOLELOGGER_H
