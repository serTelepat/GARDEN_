#pragma once

class Fruits
{
private:
	int ID_Fruits = 155;

public:

	int get_ID_Fruits() {
		return ID_Fruits;
	}

	void getHarvestOfFruits(int*** array, int x, int y) {
		array[x][y][4] = get_ID_Fruits();
	}
};

