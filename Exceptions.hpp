#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

class SettingsParsingException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to parsing Game settings.";
    }
};

#endif // EXCEPTIONS_HPP
