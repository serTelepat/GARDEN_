#pragma once
#include "UserInterface.h"
#include "GardenWithPests.h"
class UserInterface_B :
    public UserInterface
{
private:
	GardenWithPests A;

public:
	void Menu() 
	override {
		std::cout << "1. ��������������� � ������� ����." << std::endl;
		std::cout << "2. ��������� ������, ������� � �����." << std::endl;
		std::cout << "3. �������� �� ������ ��������." << std::endl;
		std::cout << "4. �������� � ������ ��������." << std::endl;
		std::cout << "5. �������� ������." << std::endl;
		std::cout << "6. ��������� ��������� ������." << std::endl;
		std::cout << "7. ��������� � ����������� ��������." << std::endl;
		std::cout << "0. �������." << std::endl;
	}

	UserInterface_B() : UserInterface() {
	};


public:
	void MenuGUI() 
	override {
		std::cout << "������� 1, ����� ������������� ����." << std::endl;
		std::cin >> numb;
		if (numb == 1) {
			while (numb != 0) {
				Menu();
				std::cin >> numb;
				switch (numb)
				{
				case 1:
					std::cout << "1. ������������� � ����� ����." << std::endl;
					std::cout << std::endl;
					std::cout << "����:" << std::endl;
					A.GardenPrint();
					std::cout << std::endl;
					break;



				case 2:
					std::cout << "2.   ��������� ��������� ������ �� n-����." << std::endl;
					std::cout << "������� ���������� ����:" << std::endl;
					std::cin >> ValueDaysWeather;
					A.GenerateWeatherAndClimate(ValueDaysWeather);
					A.GenerateVectorOfSoil(ValueDaysWeather);
					A.GenerateWeeds();

					break;

				case 3:
					std::cout << "3. �������� ����������� ��������." << std::endl;
					std::cout << "������� ID ��������:" << std::endl;
					std::cin >> id;
					std::cout << "������� ������ ����(������)" << std::endl;
					std::cin >> column_location_of_seed;
					std::cout << "������� ������ ����(�������)" << std::endl;
					std::cin >> string_location_of_seed;

					if (string_location_of_seed <= 0 || column_location_of_seed <= 0) {
						std::cout << "������ ����� ��������!" << std::endl;
						break;
					}
					else {

						if (A.getArray()[column_location_of_seed - 1][string_location_of_seed - 1][0] == 0) {
							A.GenerateSeedsOnGarden(id, column_location_of_seed, string_location_of_seed);
						}
						else {
							std::cout << "������, ���� ������!" << std::endl;
						}
						std::cout << "����:" << std::endl;
						A.GardenPrint();
						std::cout << std::endl;
						break;
					}


				case 4:
					std::cout << "4. ������� �������� � ������." << std::endl;
					std::cout << "������� ������ ����(������)" << std::endl;
					std::cin >> column_location_of_seed;
					std::cout << "������� ������ ����(�������)" << std::endl;
					std::cin >> string_location_of_seed;
					if (A.getArray()[column_location_of_seed - 1][string_location_of_seed - 1][0]) {
						A.DeleteSeedsOnGarden(column_location_of_seed, string_location_of_seed);

					}
					else {
						std::cout << "������, ���� ������" << std::endl;
					}
					std::cout << "����:" << std::endl;
					A.GardenPrint();
					std::cout << std::endl;
					break;
				case 5:
					std::cout << "���� ������:" << std::endl;
					A.PrintGardenAfterHarvest();
					std::cout << std::endl;
					break;

				case 6:
					std::cout << "6. ������ ���������� ������:" << std::endl;
					A.GenerateDroughtInGarden(1);
					std::cout << std::endl;
					break;

				case 7:

					std::cout << "7. ��������� ���������." << std::endl;
					A.Running(ValueDaysWeather);
					A.ClearToVectors(ValueDaysWeather);
					break;

				default:
					break;

				}
			}
		}
	}
};

