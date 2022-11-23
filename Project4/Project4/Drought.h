#pragma once
#include "Garden.h"

class Drought

{
private:
	const int ID_DROUGHT = 999;


public:

	const int getDrought() {
		return ID_DROUGHT;
	}

	void GenerateDroughtInGarden(int*** array, int x, int y) {
		array[x][y][3] = getDrought();
	}

};