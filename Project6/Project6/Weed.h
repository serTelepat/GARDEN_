#pragma once

class Weed

{
private:
	const int ID = 333;

public:


	void GenerateWeed(int*** array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 1; k < 2; k++) {
					array[i][j][k] = get_ID();
				}
			}
		}
	}

	const int get_ID() {
		return ID;
	}

};