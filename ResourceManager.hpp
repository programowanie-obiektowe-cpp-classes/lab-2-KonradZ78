#pragma once

#include "Resource.hpp"
#include <iostream>

class Resource {
public:
    Resource() {
        // konstruktor domyślny
    }

    double get() {
        return 6.2; // przykładowa wartość
    }
};

class ResourceManager {
private:
    Resource* res; // właściciel obiektu typu Resource

public:
    ResourceManager() : res(new Resource()) {
        // konstruktor domyślny
    }

    ResourceManager(const ResourceManager& other) : res(new Resource(*(other.res))) {
        // konstruktor kopiujący
    }

    ResourceManager& operator=(const ResourceManager& other) {
        if (this != &other) {
            delete res;
            res = new Resource(*(other.res));
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept : res(other.res) {
        other.res = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) {
            delete res;
            res = other.res;
            other.res = nullptr;
        }
        return *this;
    }

    double get() {
        return res->get();
    }

    ~ResourceManager() {
        delete res; 
    }
};
