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
        try
        {
            return resource.get();
        }
        catch (const std::exception& e)
        {
            // Obsługa błędu lub wyświetlenie informacji o błędzie
            std::cerr << "Error in ResourceManager::get(): " << e.what() << std::endl;
            return 0.0; // Lub inna wartość domyślna
        }
        catch (...)
        {
            // Obsługa innych błędów
            std::cerr << "Unknown error in ResourceManager::get()" << std::endl;
            return 0.0; // Lub inna wartość domyślna
        }
    }

private:
    Resource resource; // Owned resource
};
