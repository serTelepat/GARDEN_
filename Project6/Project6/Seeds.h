#pragma once

#include "GardenBed.h"


class Seeds
{


protected:

	int ID = 0;
	int Harvest = 5;


public:
	Seeds() {}

	Seeds(int id) {

		id = ID;
	}

	int& get_Harvest() {
		return Harvest;
	}

	void set_Harvest(int harvest) {
		harvest = Harvest;
	}

};
