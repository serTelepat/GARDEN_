#pragma once

class Vegetable
{
private:
	int ID_vegetables = 13;

public:
	int get_ID_vegetable() {
		return ID_vegetables;
	}

	void getHarvestOfVegetable(int*** array, int x, int y) {
		array[x][y][4] = get_ID_vegetable();
	}
};

