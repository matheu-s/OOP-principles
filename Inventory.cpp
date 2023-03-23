#include "Inventory.h"
#include <cmath>

void Inventory::add_item(int id, string name, std::shared_ptr<const UniversitySpec> spec)
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


        if(query.getSpec()
            && _items[i].getSpec()
            && _items[i].getSpec()->matches(*query.getSpec()))
            return _items[i];

        return _items[i];
    }

    return University{};
}

University Inventory::find_item (const UniversitySpec & query_spec) const
{
    for (size_t i = 0; i < _count; i++)
    {
        if(_items[i].getSpec() && _items[i].getSpec()->matches(query_spec))
            return _items[i];
    }

    return University{};
}
