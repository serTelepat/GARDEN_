#pragma once
#include "Garden.h"

class Manure
{
private:
	int id_manure = 1;
public:
	int get_id_manure() {
		return id_manure;
	}

	void manuring(int*** array, int x, int y) {
		array[x][y][5] = get_id_manure();
	}

	void delete_manuring(int*** array, int x, int y) {
		array[x][y][5] = get_id_manure();
	}
};