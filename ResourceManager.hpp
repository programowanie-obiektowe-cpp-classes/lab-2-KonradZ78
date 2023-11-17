#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:
    // Default constructor
    ResourceManager() : resource() {}

    // Destructor
    ~ResourceManager() = default;

    // Copy constructor
    ResourceManager(const ResourceManager &other) : resource(other.resource) {}

    ResourceManager &operator=(const ResourceManager &other)
    {
        if (this != &other)
        {
            resource = other.resource;
        }
        return *this;
    }

    // Move constructor
    ResourceManager(ResourceManager &&other) noexcept : resource(std::move(other.resource)) {}

    // Move assignment operator
    ResourceManager &operator=(ResourceManager &&other) noexcept
    {
        if (this != &other)
        {
            resource = std::move(other.resource);
        }
        return *this;
    }

    double get() const
    {
        Resource resourceCopy = resource; // Tworzenie kopii zasobu
        return resourceCopy.get(); // Wywołanie get() na kopii
    }

private:
    Resource resource; // Owned resource
};
