#pragma once
#include "Garden.h"
#include "Pests.h"

class GardenWithPests :
    public Garden
{
private:
	Pests Pests;
public:

	void PrintGardenWithPests() {
		for (int i = 0; i < getWidth(); i++) {
			for (int j = 0; j < getLenght(); j++) {
				for (int k = 0; k < 1; k++) {
					std::cout << getArray()[i][j][k] << " ";
				}
			}
			std::cout << std::endl;
		}
	}
	void Running(int value) {
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

			else if ((Weather.get_vector_Weather()[i] == 3 && getArray()[1][1][2] == 2) && (Weather.get_vector_Weather()[i - 1] == 3 && getArray()[1][1][2] == 2)) {
				Pests.GeneratePestsInGarden(array);
				GenerateWeeds();
				std::cout << std::endl << "Поле полива:" << std::endl;
				Watering.GardenMaintenancePrint(getArray());
				std::cout << std::endl << std::endl;
			}

			if (i == 5) {
				DeleteWeedInGarden();
				std::cout << std::endl;
			}

			if (i == 19) {
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

		std::cout << "Поле с болезнями/вредителями:" << std::endl;
		PrintGardenWithPests();
		std::cout << std::endl << std::endl;
	}

	void ClearToVectors(int valueDays) {
		Soil.DeleteVectorOfSoil(valueDays);
		Weather.DeleteVectorWeatherAndClimate(valueDays);
	}
};

