#include "exception.h"
#include <sstream>

Exception::Exception(const std::string& mess): m_message(mess)
{
}

Exception::~Exception() throw()
{
    //dtor
}
const char* Exception::What() const throw()
{
    return m_message.c_str();
}

AssertException::AssertException(const std::string& file, int line, std::string Message)
{
    std::ostringstream mess;
    mess << file << " (" << line << ") : " << Message;
    m_message = mess.str();
}

