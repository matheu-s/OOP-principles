#pragma once

#include <cstddef> // for std::size_t
#include <string>
#include <iostream>
#include "ItemSpec.h"

class UniversitySpec : public ItemSpec
{
    public:
        enum class Courses {ANY, SOCIOLOGIES, ENGINEERING, HEALTHS};
        static constexpr std::string_view Courses_str[] {"Any", "Sociologies", "Engineering", "Healths"};
        enum class Location {ANY, AMERICAS, EUROPE, ASIA, AFRICA, OCEANIA};
        static constexpr std::string_view Location_str[] {"Any", "Americas", "Europe", "Asia", "Africa", "Oceania"};

        UniversitySpec()
            : _tuition_price{ 0.0 },  _courses{ Courses::ANY }, _location{ Location::ANY }
            { }
        UniversitySpec(double tuition_price, Courses courses, Location location)
            : _tuition_price {tuition_price}, _courses {courses}, _location {location}
            { }

        UniversitySpec::Courses getCourses() const { return _courses; }
        UniversitySpec::Location getLocation() const { return _location; }

        bool matches(const ItemSpec & spec) const;

        void send_to(std::ostream & os) const;
        void recv_from(std::istream & is);
        friend std::istream & operator>>(std::istream & is, UniversitySpec & spec);
    private:
        double _tuition_price;
        Courses _courses;
        Location _location;
};


std::ostream & operator<<(std::ostream & os, UniversitySpec::Courses courses);
std::istream & operator>>(std::istream & is, UniversitySpec::Courses & courses);

std::ostream & operator<<(std::ostream & os, UniversitySpec::Location location);
std::istream & operator>>(std::istream & is, UniversitySpec::Location & location);

std::ostream & operator<<(std::ostream & os, const UniversitySpec & spec);
