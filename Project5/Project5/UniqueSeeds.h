#pragma once
#include "Seeds.h"

class UniqueSeeds :
    public Seeds
{
private:

public:
    UniqueSeeds() {}
    UniqueSeeds(int id) : Seeds(id) {};

};

