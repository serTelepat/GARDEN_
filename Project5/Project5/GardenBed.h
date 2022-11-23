#pragma once
#include "Garden.h"
#include "Seeds.h"

class GardenBed
{
private:
    Seeds Seed;

public:
    GardenBed() {}

    void set_width(int valueWidth) {
        const int width = valueWidth;
    }


    virtual void GeneratePlantTreeBushOnGardenBed(int*** array, int id, int valuePossitionWidth, int valuePossitionHight) {
        Seeds(idd);
        array[valuePossitionWidth][valuePossitionHight][0] = id;

    }

    virtual void DeletePlantTreeBushOnGardenBed(int*** array, int valuePossitionWidth, int valuePossitionHight) {

        array[valuePossitionWidth][valuePossitionHight][0] = 0;
    }

    int GrowingAndGenerateHarvest() {
        return Seed.get_Harvest();
    }

};

