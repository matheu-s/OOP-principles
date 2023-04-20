#include "University.h"

#include <string>

std::ostream & operator<<(std::ostream & os, const University & item)
{
    item.send_to(os);
    return os;
}

void University::send_to(std::ostream & os) const
{
    os << _id << ';'
       << _name;

    if (_spec)
    {
        os << ';';
        _spec->send_to(os);
    }
}