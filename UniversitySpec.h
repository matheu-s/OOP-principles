#pragma once

#include <cstddef> // for std::size_t
#include <string>

class UniversitySpec
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
        std::string_view getCoursesStr() const { return Courses_str[(std::size_t)_courses]; }
        
        UniversitySpec::Location getLocation() const { return _location; }
        std::string_view getLocationStr() const { return Location_str[(std::size_t)_location]; }
        
        double getTuitionPrice() const { return _tuition_price; }

        bool matches(const UniversitySpec & spec) const;
    
    private:
        double _tuition_price;
        Courses _courses;
        Location _location;
};