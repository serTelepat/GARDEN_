#pragma once
#include <iostream>
#include <vector>

#include "GardenBed.h"
#include "Weeding.h"
#include "Weather.h"
#include "Fruits.h"
#include "Drought.h"
#include "Seeds.h"
#include "Tree.h"
#include "Vegetable.h"
#include "Weed.h"
#include "Manure.h"
#include "Soil.h"
#include "Sun.h"
#include "Rain.h"
#include "Watering.h"

class Garden
{
public:
	GardenBed TestGardenBed;
	Weeding Weeding;
	Weather Weather;
	Drought Drought;
	Tree Tree;
	Vegetable Vegetable;
	Weed Weed;
	Manure Manure;
	Soil Soil;
	Sun Sun;
	Rain Rain;
	Watering Watering;
	Fruits Fruits;
protected:

	int*** array;
private:
	std::vector<int> getHarvestFromGarden;
	int length = 20;
	int width = 10;
	int depth = 5;

	int l = 0;

public:
	Garden() {

		array = new int** [width];
		for (int i = 0; i < width; i++) {
			array[i] = new int* [length];
			for (int j = 0; j < length; j++) {
				array[i][j] = new int[depth];
			}
		}

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++) {
				for (int k = 0; k < depth; k++) {
					array[i][j][k] = 0;
				}
			}
		}
	}

	~Garden() {
		for (int j = 0; j < depth; j++) {

			for (int i = 0; i < width; i++) {
				delete[] array[j][i];
			}
			delete[] array[j];
		}
		delete[] array;
	}

	void GardenPrint() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++) {
				for (int k = 0; k < 1; k++) {
					std::cout << getArray()[i][j][k] << " ";
				}

			}
			std::cout << std::endl;
		}
	}

	void GardenPrintWithWeed() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++) {
				for (int k = 1; k < 2; k++) {
					std::cout << getArray()[i][j][k] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void GenerateSimulationOfWatering() {
		Watering.GenerateExcessWater(getArray());

	}

	void DeleteWeedInGarden() {
		Weeding.DeleteWeedsFromGarden(getArray());
	}

	void GenerateWeeds() {
		for (int l = 0; l < Weather.get_vector_Weather().size(); l++) {
			if (Weather.get_vector_Weather()[l] == Rain.get_DayRain()) {
				Weed.GenerateWeed(array);
			}
			else {
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < length; j++) {
						for (int k = 1; k < 2; k++) {
							array[i][j][k] = array[i][j][k];
						}
					}
				}
			}
		}
	}

	void GardenPrintWithManure() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++) {
				std::cout << array[i][j][5] << " ";
			}
			std::cout << std::endl;
		}
	}

	void PrintWeather() {
		Weather.PrintWeather();
	}

	void PrintClimate() {
		Weather.PrintClimate();
	}

	void GenerateVectorOfSoil(int ValueDays) {
		Soil.GenerateVectorSoil(ValueDays, Weather.get_vector_Climate());
	}

	void PrintVectorOfSoil() {
		Soil.PrintVectorSoil();
	}

	void PrintGardenAfterHarvest() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length; j++) {
				std::cout << getArray()[i][j][4] << " ";
			}
			std::cout << std::endl;
		}
	}

	void GenerateDroughtInGarden(int count) {
		for (int counter_x = 0; counter_x < getWidth(); counter_x++) {
			for (int counter_j = 0; counter_j < getLenght(); counter_j++) {
				Drought.GenerateDroughtInGarden(array, counter_x, counter_j);
				TestGardenBed.DeletePlantTreeBushOnGardenBed(array, counter_x, counter_j);
			}
		}

	}

	void getDrought() {
		Drought.getDrought();
	}

	void GenerateWeatherAndClimate(int valueDays) {
		Weather.GenerateWeatherAndClimate(valueDays);
	}

	virtual void GenerateSeedsOnGarden(int id, int column_location_of_seed, int string_location_of_seed) {
		TestGardenBed.GeneratePlantTreeBushOnGardenBed(array, id, column_location_of_seed - 1, string_location_of_seed - 1);
	}

	void DeleteSeedsOnGarden(int column_location_of_seed, int string_location_of_seed) {
		TestGardenBed.DeletePlantTreeBushOnGardenBed(array, column_location_of_seed - 1, string_location_of_seed - 1);
	}

	GardenBed getTest() {
		return TestGardenBed;
	}

	void ChangeOfGardenToTree(int x, int y) {
		if (array[x][y][0] == 0) {
			Tree.ChangeGarden(array, x, y);
		}
		else {
			std::cout << "Поле уже занято, выберите другую ячейку" << std::endl;
		}
	}

	int Growing() {
		return TestGardenBed.GrowingAndGenerateHarvest();
	}

	int*** getArray() {
		return array;
	}


protected:

	int getWidth() {
		return width;
	}

	int getLenght() {
		return length;
	}

	int getDepth() {
		return depth;
	}

public:



	virtual void Running(int value) {
		for (int i = 0; i < value; i++) {

			if (Weather.get_vector_Weather()[i] == 1) {
				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][0] != 0) {
							Watering.GenerateWatering_1(getArray(), t, j);
						}
					}
				}

				std::cout << std::endl << "Поле полива:" << std::endl;
				Watering.GardenMaintenancePrint(getArray());
				std::cout << std::endl << std::endl;

				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][2] != 0) {
							Watering.GenerateWatering_0(getArray(), t, j);
						}
					}
				}
			}

			else if (Weather.get_vector_Weather()[i] == 3) {
				Watering.GenerateExcessWater(getArray());
				GenerateWeeds();
				std::cout << std::endl << "Поле полива:" << std::endl;
				Watering.GardenMaintenancePrint(getArray());
				std::cout << std::endl << std::endl;
				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][2] != 0) {
							Watering.GenerateWatering_0(getArray(), t, j);
						}
					}
				}
			}

			if (i % 5 == 0) {
				DeleteWeedInGarden();
				std::cout << std::endl;
			}

			if (i % 19 == 0) {
				for (int i = 0; i < getWidth(); i++) {
					for (int j = 0; j < getLenght(); j++) {
						if (array[i][j][0] != 0) {
							//fruits
							if (array[i][j][0] < 20) {
								Fruits.getHarvestOfFruits(array, i, j);
							}
							//vegetables
							else if (array[i][j][0] > 20 && array[i][j][0] < 60) {
								Vegetable.getHarvestOfVegetable(array, i, j);
							}
							//Trees
							else {
								Tree.getHarvestOfTrees(array, i, j);
							}
						}
					}
				}

				if (i % 10 == 0) {
					for (int w = 0; w < getWidth(); w++) {
						for (int h = 0; h < getLenght(); h++) {
							Manure.manuring(array, w, h);
						}
					}
				}

				if (i % 5 == 0) {
					for (int w = 0; w < getWidth(); w++) {
						for (int h = 0; h < getLenght(); h++) {
							Manure.delete_manuring(array, w, h);
						}
					}
				}
			}

			std::cout << std::endl << "Поле:" << std::endl;
			GardenPrint();
			std::cout << std::endl << std::endl;

			std::cout << "Поле с травой:" << std::endl;
			GardenPrintWithWeed();
			std::cout << std::endl << std::endl;

			std::cout << "Поле с удобрениями:" << std::endl;
			GardenPrintWithManure();
			std::cout << std::endl << std::endl;

			system("pause");
			system("cls");
		}
		std::cout << "Поле с урожаем:" << std::endl;
		PrintGardenAfterHarvest();
		std::cout << std::endl << std::endl;

	}

	void ClearToVectors(int valueDays) {
		Soil.DeleteVectorOfSoil(valueDays);
		Weather.DeleteVectorWeatherAndClimate(valueDays);
	}

};
