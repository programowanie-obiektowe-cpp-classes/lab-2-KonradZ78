#pragma once

#include "Resource.hpp"
#include <iostream>

class ResourceManager
{
public:
    ResourceManager() : resource() {}

    double get() { return resource.get(); }

private:
    Resource resource;
};
