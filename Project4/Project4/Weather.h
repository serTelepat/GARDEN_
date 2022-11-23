#pragma once
#include "Garden.h"
#include "Rain.h"
#include "Sun.h"

class Weather
{
private:
	std::vector<int> vector_Weather;
	std::vector<int> vector_Climate;

public:
	Rain Rain;
	Sun Sun;

	void GenerateWeatherAndClimate(int numberDays_Weather) {
		srand(time(NULL));
		//генерация погоды b климата на n-количество дней
		vector_Weather.push_back(1);
		vector_Climate.push_back(1);
		for (int counter = 1; counter < numberDays_Weather; counter++) {
			vector_Weather.push_back(1 + rand() % 4);
			//дождь
			if (vector_Weather[counter] == Rain.get_DayRain()) {
				vector_Weather[counter] = Rain.get_DayRain();
				vector_Climate.push_back(2);
				Rain.PrintDayRain(counter);
				
			}

			//солнце
			else {
				vector_Weather[counter] = Sun.get_DaySun();
				vector_Climate.push_back(Sun.get_DaySun());
				Sun.PrintSun(counter);
			}
		}
	}

	void DeleteVectorWeatherAndClimate(int numberDays_Weather) {
		for (int i = 0; i < numberDays_Weather; i++) {
			vector_Climate.pop_back();
			vector_Weather.pop_back();
		}
	}

	void PrintWeather() {
		std::cout << "[";
		for (int counter = 0; counter < vector_Weather.size(); counter++) {
			std::cout << vector_Weather[counter] << " ";
		}
		std::cout << "]" << std::endl;
	}

	void PrintClimate() {
		std::cout << "[";
		for (int counter = 0; counter < vector_Climate.size(); counter++) {
			std::cout << vector_Climate[counter] << " ";
		}
		std::cout << "]" << std::endl;

	}

	std::vector<int>& get_vector_Climate() {
		return vector_Climate;
	}

	std::vector<int>& get_vector_Weather() {
		return vector_Weather;
	}
};

