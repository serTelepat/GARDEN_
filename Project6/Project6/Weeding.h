#pragma once
#include "Garden.h"

class Weeding

{
private:
	const int ID = 0;
public:
	int get_ID_Weeding() {
		return ID;
	}


	void DeleteWeedsFromGarden(int*** array) {

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 1; k < 2; k++) {
					array[i][j][k] = get_ID_Weeding();
				}
			}
		}

	}
};