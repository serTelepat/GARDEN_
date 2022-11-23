#pragma once
#include "Drought.h";
#include "GardenWithPests.h"

class Pests:
	public Drought
{
private:
	std::vector<int> pests_vector;

public:

	int GenerateVectorOfPests() {
		pests_vector.push_back(150 + rand() % 50);
		return get_pests_vector().size();
	}

	void GeneratePestsInGarden(int*** array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				array[i][j][3] = GenerateVectorOfPests();
			}
		}
	}

	void DeletePestInGarden(int*** array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				array[i][j][3] = 0;
			}
		}
	}

	int DeletePestsFromVector() {
		if (pests_vector.empty() != true) {
			pests_vector.pop_back();
		}
		return get_pests_vector().size();
	}

	std::vector<int>& get_pests_vector() {
		return pests_vector;
	}
};



