#pragma once
#ifndef INVENTORY
#define INVENTORY

#include <memory>
#include "University.h"
#include "ItemSpec.h"
#include "Item.h"
using namespace std;

class Inventory
{
    public:
        Inventory()
            : _count{0}
            {}

        const University & operator[](size_t i) const { return this->get_item(i);}
        const Item & get_item(size_t i) const
        {
            if (i < _count) return *_items[i];

            throw std::out_of_range("Invalid index value.");
        }

        const Item & find_item(const ItemSpec & otherSpec) const;
        
        void add_item(std::shared_ptr<Item> newItem);
    private:
        static const size_t MAX_SIZE{ 20 };

        // An array for storing abstraction objects
        std::shared_ptr<Item> _items[Inventory::MAX_SIZE];

        size_t _count;
};

#endif