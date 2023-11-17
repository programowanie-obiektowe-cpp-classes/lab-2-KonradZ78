#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:
    // Default constructor
    ResourceManager() : resource(new Resource()) {}

    // Destructor
    ~ResourceManager(){
        delete resource;
    };

    // Copy constructor
    ResourceManager(const ResourceManager& other) : (new Resource(*other.resource)) {};

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other)
        {
            delete resource;
            resource=new Resource(*other.resource);
        }
        return *this;
    }

    // Move constructor
    ResourceManager(ResourceManager&& other): resource(other.resource) {
        other.resource=nullptr;
    };

    // Move assignment operator
    ResourceManager& operator=(ResourceManager&& other) 
    {
        if (this != &other)
        {
            delete resource;
            resource=other.resource;
            other.resource=nullptr;
        }
        return *this;
    }

    double get() const
    {
        return resourceCopy->get(); // Wywołanie get() na kopii
    }

private:
    Resource* resource; // Owned resource
};
