#pragma once
#include "Watering.h"

class UniqueWatering :
    public Watering
{
public:
	void GenerateWatering_1(int*** array, int valuePossitionWidth, int valuePossitionHight) 
		override {
		array[valuePossitionWidth][valuePossitionHight][2] += 2;
	}

	void GenerateWatering_1(int*** array, int watering, int valuePossitionWidth, int valuePossitionHight)
	{
		array[valuePossitionWidth][valuePossitionHight][2] += watering;
	}

};

