#pragma once
#include "Garden.h"
#include "GardenBedWithUniqueSeeds.h"
#include "UniqueWatering.h"

class GardenWithUniqueSeeds :
    public Garden
{
private:
	GardenBedWithUniqueSeeds GardenBedWithUniqueSeeds;
	UniqueWatering UniqueWatering;

public:
	void GenerateSeedsOnGarden(int id, int column_location_of_seed, int string_location_of_seed) 
	{
		GardenBedWithUniqueSeeds.GeneratePlantTreeBushOnGardenBed(array, id, column_location_of_seed - 1, string_location_of_seed - 1);
	}

	void Running(int value, int watering) 
	{
		for (int i = 0; i < value; i++) {

			if (Weather.get_vector_Weather()[i] == 1) {
				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][0] != 0){
							if (getArray()[t][j][0] > 100) {
								UniqueWatering.GenerateWatering_1(getArray(), watering, t, j);
							}
							else {
								UniqueWatering.GenerateWatering_1(getArray(), t, j);
							}
						}
					}
				}

				std::cout << std::endl << "Поле полива:" << std::endl;
				Watering.GardenMaintenancePrint(getArray());
				std::cout << std::endl << std::endl;

				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][2] != 0) {
							UniqueWatering.GenerateWatering_0(getArray(), t, j);
						}
					}
				}
			}

			else if (Weather.get_vector_Weather()[i] == 3) {
				UniqueWatering.GenerateExcessWater(getArray());
				GenerateWeeds();
				std::cout << std::endl << "Поле полива:" << std::endl;
				UniqueWatering.GardenMaintenancePrint(getArray());
				std::cout << std::endl << std::endl;
				for (int t = 0; t < getWidth(); t++) {
					for (int j = 0; j < getLenght(); j++) {
						if (getArray()[t][j][2] != 0) {
							UniqueWatering.GenerateWatering_0(getArray(), t, j);
						}
					}
				}
			}

			if (i % 5 == 0) {
				for (int w = 0; w < getWidth(); w++) {
					for (int h = 0; h < getLenght(); h++) {
						Manure.delete_manuring(array, w, h);
					}
				}
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

};

