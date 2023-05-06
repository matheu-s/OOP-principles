#include <iostream>
#include "University.h"
#include "Inventory.h"
#include "UniversitySpec.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(const Item & item)
{
    cout << item << "\n";
}

// solution entry function
int main()
{
    Inventory inv;

    std::shared_ptr<UniversitySpec> spec_uni{ new UniversitySpec(20.500, UniversitySpec::Courses::ENGINEERING, UniversitySpec::Location::EUROPE)};
    inv.add_item(1, "Riga Technical University", spec_uni);
    inv.add_item(2, "Tallinn University of Technology", spec_uni);



    //creating university objects which are only being served as query type for inventory
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    std::shared_ptr<UniversitySpec> look_spec_uni{ new UniversitySpec(20.500, UniversitySpec::Courses::ENGINEERING, UniversitySpec::Location::EUROPE)};
    show(inv.find_item(University{0, "Riga Technical University", look_spec_uni}));

    std::shared_ptr<UniversitySpec> look_spec_uni2{ new UniversitySpec(20.200, UniversitySpec::Courses::HEALTHS, UniversitySpec::Location::OCEANIA)};
    show(inv.find_item(University{2, "", look_spec_uni2}));

    return 0;
}