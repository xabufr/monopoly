#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
/// @todo Documenter
class Exception : public std::exception
{
    public:
        Exception(const std::string &mess="");
        virtual ~Exception() throw();

        virtual const char* What() const throw();
    protected:
        std::string m_message;
};
class AssertException: public Exception
{
    public:
        AssertException(const std::string& file, int line, std::string Message);
};
#ifdef _DEBUG
        #define Assert(condition) if(!(condition)) throw AssertException(__FILE__, __LINE__, "AssertException: " #condition)
    #else
        inline void DoNothing(bool){}
        #define Assert(condition) DoNothing(!(condition))
    #endif

#endif // EXCEPTION_H
