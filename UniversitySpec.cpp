#include "UniversitySpec.h"

bool UniversitySpec::matches(const UniversitySpec & spec) const
{
    if(this == &spec)
        return true;

    if(Courses::ANY != spec.getCourses() && _courses != spec.getCourses())
        return false;

    if(Location::ANY != spec.getLocation() && _location != spec.getLocation())
        return false;

    return true;
}
