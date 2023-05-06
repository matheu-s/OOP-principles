#include "UniversitySpec.h"

#include <string> // for std::getline()

#ifdef _MSC_VER // Visual C++ ?
    #define strcasecmp _stricmp // then use the function _stricmp()
#else
    #include <strings.h> // for strcasecmp() function in POSIX C++
#endif

bool UniversitySpec::matches(const ItemSpec & spec) const
{
    if(this == &spec)
        return true;

    if(Courses::ANY != spec.getCourses() && _courses != spec.getCourses())
        return false;

    if(Location::ANY != spec.getLocation() && _location != spec.getLocation())
        return false;

    return true;
}

std::ostream & operator<<(std::ostream & os, UniversitySpec::Courses courses)
{
   return os << UniversitySpec::Courses_str[static_cast<size_t>(courses)];
}

std::ostream & operator<<(std::ostream & os, UniversitySpec::Location location)
{
   return os << UniversitySpec::Location_str[static_cast<size_t>(location)];
}

std::ostream & operator<<(std::ostream & os, const UniversitySpec & spec)
{
    spec.send_to(os);
    return os;
}

void UniversitySpec::send_to(std::ostream & os) const {
    os << _courses << ';'
       << _location << ';'
       << _tuition_price;
}

std::istream & operator>>(std::istream & is, UniversitySpec::Courses & courses)
{
    if (is)
    {
        std::string tmp;
        std::getline(is, tmp, ';');
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(UniversitySpec::Courses_str)/sizeof(UniversitySpec::Courses_str[0]); i++)
            {
                if (tmp.length() == UniversitySpec::Courses_str[i].length()
					&& 0 == strcasecmp(tmp.c_str(), std::string(UniversitySpec::Courses_str[i]).c_str())) // case insensitive comparison
                {
                    courses = static_cast<UniversitySpec::Courses>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                courses = UniversitySpec::Courses::ANY;
        }
    }

    return is;
}

std::istream & operator>>(std::istream & is, UniversitySpec::Location & location)
{
    if (is)
    {
        std::string tmp;
        std::getline(is, tmp, ';');
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(UniversitySpec::Location_str)/sizeof(UniversitySpec::Location[0]); i++)
            {
                if (tmp.length() == UniversitySpec::Location_str[i].length()
					&& 0 == strcasecmp(tmp.c_str(), std::string(UniversitySpec::Location_str[i]).c_str())) // case insensitive comparison
                {
                    location = static_cast<UniversitySpec::Location>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                location = UniversitySpec::Location::ANY;
        }
    }

    return is;
}

std::istream & operator>>(std::istream & is, UniversitySpec & item)
{
    item.recv_from(is);
    return is;
}

void UniversitySpec::recv_from(std::istream & is) {
    if (is)
        is >> _courses;
    if (is)
        (is >> _location).ignore();
    if (is)
        (is >> _tuition_price).ignore();
}
