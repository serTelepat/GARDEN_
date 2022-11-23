#pragma once
#include "Garden.h"

class Watering
{

public:

	virtual void GenerateWatering_1(int*** array, int valuePossitionWidth, int valuePossitionHight) {
		array[valuePossitionWidth][valuePossitionHight][2] += 2;
	}

	void GenerateWatering_0(int*** array, int valuePossitionWidth, int valuePossitionHight) {
		{
			array[valuePossitionWidth][valuePossitionHight][2] = 0;
		}
	}

	void GardenMaintenancePrint(int*** array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 2; k < 3; k++) {
					std::cout << array[i][j][k] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void GenerateExcessWater(int*** array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 2; k < 3; k++)
					array[i][j][k] = 2;
			}

		}
	}
};

