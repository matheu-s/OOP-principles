#pragma once
#ifndef INVENTORY
#define INVENTORY

#include <memory>
#include "University.h"
using namespace std;

class Inventory
{
    public:
        Inventory()
            : _count{0}
            {}

        const University & operator[](size_t i) const { return this->get_item(i);}
        const University & get_item(size_t i) const
        {
            if (i < this->_count) return this->_items[i];

            throw std::out_of_range("Invalid index value.");
        }

        University find_item(const University & query) const;
        University find_item(const UniversitySpec & query) const;
        
        void add_item(int id, string name, std::shared_ptr<const UniversitySpec> spec);

    private:
        static const size_t MAX_SIZE{ 20 };

        // An array for storing abstraction objects
        University _items[Inventory::MAX_SIZE];

        size_t _count;
};

#endif