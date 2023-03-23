#pragma once
#ifndef UNIVERSITY
#define UNIVERSITY

#include <string>
#include <memory>
#include "UniversitySpec.h"  // !!

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

    private:
        int _id;
        string _name;
        std::shared_ptr<const UniversitySpec> _spec;
};

#endif