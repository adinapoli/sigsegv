#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <iostream>

class SettingsParsingException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to parsing Game settings.";
    }
};

class ObjectNotFoundInSettingsException: public std::exception
{
public:
    ObjectNotFoundInSettingsException(const std::string& objName):
        objName_(objName){}

    virtual ~ObjectNotFoundInSettingsException() throw(){}

    virtual const char* what() const throw()
    {
        std::string errorMsg =  "Couldn't find " + objName_ + " in settings.";
        std::cout << errorMsg << std::endl;
        return errorMsg.c_str();
    }

private:
    std::string objName_;
};

#endif // EXCEPTIONS_HPP
