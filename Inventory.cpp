#include "Inventory.h"
#include <cmath>

void Inventory::add_item(int id, string name, const UniversitySpec & spec)
{
    if (_count < Inventory::MAX_SIZE)
    {
        University new_item(id, name, spec);
        _items[_count] = new_item;
        _count++;
    }
}

//University here before Inventory bc is the type returned
University Inventory::find_item (const University & query) const
{
    auto query_spec{ query.getSpec() };
    for (size_t i = 0; i < _count; i++)
    {
        // for integer and boolean type property
        if (query.getId() != 0
            && query.getId() != _items[i].getId())
            continue;

        // for string type property
        if (query.getName() != ""
            && query.getName() != _items[i].getName())
            continue;

        auto item_spec{ _items[i].getSpec() };

        // for double type
        constexpr double epsil{ 0.005 };
        if (query_spec.getTuitionPrice() != 0.0
            && epsil < std::abs(query_spec.getTuitionPrice() - item_spec.getTuitionPrice()))
            continue;

		if (query_spec.getCourses() != UniversitySpec::Courses::ANY
			&& query_spec.getCourses() != item_spec.getCourses())
            continue;

		if (query_spec.getLocation() != UniversitySpec::Location::ANY
			&& query_spec.getLocation() != item_spec.getLocation())
            continue;

        return _items[i];
    }

    return University{};
}

University Inventory::find_item (const UniversitySpec & query_spec) const
{
    for (size_t i = 0; i < _count; i++)
    {
        auto item_spec{ _items[i].getSpec() };

        constexpr double epsil{ 0.005 };
        if (query_spec.getTuitionPrice() != 0.0
            && epsil < std::abs(query_spec.getTuitionPrice() - item_spec.getTuitionPrice()))
            continue;

		if (query_spec.getCourses() != UniversitySpec::Courses::ANY
			&& query_spec.getCourses() != item_spec.getCourses())
            continue;

		if (query_spec.getLocation() != UniversitySpec::Location::ANY
			&& query_spec.getLocation() != item_spec.getLocation())
            continue;

        return _items[i];
    }

    return University{};
}
