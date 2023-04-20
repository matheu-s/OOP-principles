#pragma once
#ifndef UNIVERSITY
#define UNIVERSITY

#include "UniversitySpec.h"
#include <string>
#include <memory>
#include <iostream>


using namespace std;

class University
{
    public:
        University()
            : _id{ 0 }, _name{ "" }, _spec{ }
            { }
        University(int id, string name, std::shared_ptr<const UniversitySpec> spec)
            : _id{ id }, _name{ name }, _spec{ spec }
            { }

        int getId() const { return _id; }
        string getName() const { return _name; }
        std::shared_ptr<const UniversitySpec> getSpec() const { return _spec; }

        void send_to(std::ostream & os) const;
    private:
        int _id;
        string _name;
        std::shared_ptr<const UniversitySpec> _spec;
};

std::ostream & operator<<(std::ostream & os, const University & item);


#endif