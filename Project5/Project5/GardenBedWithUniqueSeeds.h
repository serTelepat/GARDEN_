#pragma once
#include "GardenBed.h"
#include "UniqueSeeds.h"

class GardenBedWithUniqueSeeds :
    public GardenBed
{
public:

    void GeneratePlantTreeBushOnGardenBed(int*** array, int id, int valuePossitionWidth, int valuePossitionHight) 
    override {
        UniqueSeeds(ids);
        array[valuePossitionWidth][valuePossitionHight][0] = id;

    }
};

