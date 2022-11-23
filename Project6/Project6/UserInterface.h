#pragma once
#include "Garden.h"

class UserInterface
{
private:
	Garden A;

public:
	virtual void Menu() {
		std::cout << "1. ��������������� � ������� ����." << std::endl;
		std::cout << "2. ��������� ������, ������� � �����." << std::endl;
		std::cout << "3. �������� �� ������ ��������." << std::endl;
		std::cout << "4. �������� � ������ ��������." << std::endl;
		std::cout << "5. �������� � ������ ��������." << std::endl;
		std::cout << "6. ��������� ��������� ������" << std::endl;
		std::cout << "7. ���������." << std::endl;
		std::cout << "0. �������." << std::endl;
	}

	UserInterface() {
		setlocale(LC_ALL, "Russian");
	};

protected:
	int n = 0;
	int id = 0;
	int numb = 0;
	int string_location_of_seed = 0;
	int column_location_of_seed = 0;
	int depth_location = 0;
	int ValueDaysWeather = 0;

public:
	virtual void MenuGUI() {
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
					std::cout << "������� ������ � ������?(1 - ��; 0 -  ���)." << std::endl;
					std::cin >> n;
					A.GenerateVectorOfSoil(ValueDaysWeather);
					A.GenerateWeeds();
					if (n == 1) {
						std::cout << "������:" << std::endl;
						A.PrintWeather();
						std::cout << std::endl;
						std::cout << "������:" << std::endl;
						A.PrintClimate();
						std::cout << std::endl;
						std::cout << "������� �������� �����?(1 - ��; 0 - ���)." << std::endl;
						std::cin >> n;
						if (n == 1) {
							std::cout << std::endl;
							std::cout << "�����:" << std::endl;
							A.PrintVectorOfSoil();
							std::cout << std::endl;
						}

						break;

					}
					else {
						break;
					}
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