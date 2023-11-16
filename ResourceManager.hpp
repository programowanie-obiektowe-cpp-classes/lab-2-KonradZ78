#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager {
private:
    Resource resource; // Właściciel obiektu typu Resource

public:
    ResourceManager() : resource() {
        // Konstruktor domyślny
    }

    
    ResourceManager(const ResourceManager& other) : resource(other.resource) {
    }

    
    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    ~ResourceManager() {
        // Implementacja destruktora
    }

    double get() {
        return resource.get(); // Zwraca wynik wywołania metody get obiektu, którym zarządza
    }
};
