#pragma once
#ifndef INVENTORY
#define INVENTORY

#include "University.h"

class Inventory
{
    public:
        Inventory()
            : _count{0}
            {}

        University find_item(const University & query) const;
        University find_item(const UniversitySpec & query) const;
        
        void add_item(int id, string name, const UniversitySpec & spec);



    private:
        static const size_t MAX_SIZE{ 20 };

        // An array for storing abstraction objects
        University _items[Inventory::MAX_SIZE];

        size_t _count;
};

#endif