#pragma once
#include "Garden.h"

class Vegetable
{
private:
	int ID_vegeables = 13;

public:
	int get_ID_vegetable() {
		return ID_vegeables;
	}

	void getHarvestOfVegetable(int*** array, int x, int y) {
		array[x][y][4] = get_ID_vegetable();
	}
};

