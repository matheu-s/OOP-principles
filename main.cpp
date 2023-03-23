#include <iostream>
#include "University.h"
#include "Inventory.h"
#include "UniversitySpec.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(const University & item)
{
    auto is { item.getSpec() };

    cout << item.getId() << " "
        << "'" << item.getName() << "' "
        << "'" << is.get_courses_str() << "' "
        << "'" << is.get_location_str() << "' "
        << is.getTuitionPrice() << " "
        << endl;
}

// solution entry function
int main()
{
    Inventory inv;

    // adds several different abstraction objects to the inventory
    UniversitySpec spec_uni{ 20.500, UniversitySpec::Courses::ENGINEERING, UniversitySpec::Location::EUROPE};
    inv.add_item(1, "Riga Technical University", spec_uni);
    inv.add_item(2, "Tallinn University of Technology", spec_uni);



    //creating university objects which are only being served as query type for inventory
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    show(inv.find_item(University{0, "Riga Technical University", UniversitySpec{ }}));

    show(inv.find_item(University{2, "", UniversitySpec{ 0.0, UniversitySpec::Courses::ENGINEERING, UniversitySpec::Location::ANY }}));

    return 0;
}