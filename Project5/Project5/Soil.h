#pragma once
#include "Garden.h"
#include "Rain.h"
#include "Sun.h"

class Soil
{
private:
	int state_of_soil = 0;
	int count_normal_days = 0;

	const int NORMAL_STATE = 2;

	std::vector<int> vector_of_soil;

public:
	Rain Rain;
	Sun Sun;


	Soil() {};

	void GenerateVectorSoil(int valueDays, std::vector<int> Weather_Vector) {

		for (int i = 0; i < valueDays; i++) {

			if (Weather_Vector[i] == Sun.get_DaySun()) {
				vector_of_soil.push_back(get_NORMAL_STATE());
				Count_Normal_Days();
			}

			else if (get_count_normal_days() > 3 && Weather_Vector[i] == Sun.get_DaySun()) {
				vector_of_soil.push_back(get_NORMAL_STATE() + 1);
				Count_Normal_Days();
			}

			else if (get_count_normal_days() > 4 && Weather_Vector[i] == 1) {
				vector_of_soil.push_back(get_NORMAL_STATE() + 2);

			}

			else {
				vector_of_soil.push_back(get_NORMAL_STATE() - 2);
			}
		}
	};

	void PrintVectorSoil() {
		std::cout << "[";
		for (int i = 0; i < vector_of_soil.size(); i++) {
			std::cout << vector_of_soil[i] << " ";
		}
		std::cout << "]" << std::endl;
	}

	void DeleteVectorOfSoil(int numberDays_Weather) {
		for (int i = 0; i < numberDays_Weather; i++) {
			vector_of_soil.pop_back();
		}
	}

	const int get_NORMAL_STATE() {
		return NORMAL_STATE;
	}

	int get_state_of_soil() {
		return state_of_soil;
	}

	int get_count_normal_days() {
		return count_normal_days;
	}

	int Count_Normal_Days() {
		return count_normal_days++;
	}

	void set_count_normal_days() {
		count_normal_days = Count_Normal_Days();
	}

	std::vector<int>& get_vector_of_soil() {
		return vector_of_soil;
	}
};