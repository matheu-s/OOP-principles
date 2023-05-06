#include "University.h"

#include <string>

std::ostream & operator<<(std::ostream & os, const University & item)
{
    item.send_to(os);
    return os;
}

void University::send_to(std::ostream & os) const
{
    Item::send_to(os);

    os << _id << ';'
       << _name;
}