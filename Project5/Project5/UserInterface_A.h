#pragma once
#include "UserInterface.h"
#include "GardenWithUniqueSeeds.h"

class UserInterface_A :
    public UserInterface
{
private:
	GardenWithUniqueSeeds A;

public:
	void Menu() 
		override {
		std::cout << "1. Сгенеририровать и вывести поле." << std::endl;
		std::cout << "2. Генератор погоды, климата и почвы." << std::endl;
		std::cout << "3. Посадить на грядку растение." << std::endl;
		std::cout << "4. Удаление с грядки растения." << std::endl;
		std::cout << "5. Посадить своё растение." << std::endl;
		std::cout << "6. Сбор урожая." << std::endl;
		std::cout << "7. Запустить генератор засухи" << std::endl;
		std::cout << "8. Запустить." << std::endl;
		std::cout << "0. Закрыть." << std::endl;
	}

	int watering = 0;
	 
	void MenuUI() 
		override {
		std::cout << "Нажмите 1, чтобы сгенерировать поле." << std::endl;
		std::cin >> numb;
		if (numb == 1) {
			while (numb != 0) {
				Menu();
				std::cin >> numb;
				switch (numb)
				{
				case 1:
					std::cout << "1. Генерирование и вывод поля." << std::endl;
					std::cout << std::endl;
					std::cout << "Поле:" << std::endl;
					A.GardenPrint();
					std::cout << std::endl;
					break;



				case 2:
					std::cout << "2.   Запустить генератор погоды на n-дней." << std::endl;
					std::cout << "Введите количество дней:" << std::endl;
					std::cin >> ValueDaysWeather;
					A.GenerateWeatherAndClimate(ValueDaysWeather);
					std::cout << "Вывести погоду и климат?(1 - Да; 0 -  Нет)." << std::endl;
					std::cin >> n;
					A.GenerateVectorOfSoil(ValueDaysWeather);
					A.GenerateWeeds();
					if (n == 1) {
						std::cout << "Погода:" << std::endl;
						A.PrintWeather();
						std::cout << std::endl;
						std::cout << "Климат:" << std::endl;
						A.PrintClimate();
						std::cout << std::endl;
						std::cout << "Вывести состония почвы?(1 - Да; 0 - Нет)." << std::endl;
						std::cin >> n;
						if (n == 1) {
							std::cout << std::endl;
							std::cout << "Почва:" << std::endl;
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
					std::cout << "3. Посадить стандартное растение." << std::endl;
					std::cout << "Введите ID растения:" << std::endl;
					std::cin >> id;
					std::cout << "Введите ячейку поля(строка)" << std::endl;
					std::cin >> column_location_of_seed;
					std::cout << "Введите ячейку поля(столбец)" << std::endl;
					std::cin >> string_location_of_seed;

					if (string_location_of_seed <= 0 || column_location_of_seed <= 0) {
						std::cout << "Ошибка ввода значений!" << std::endl;
						break;
					}
					else {

						if (A.getArray()[column_location_of_seed - 1][string_location_of_seed - 1][0] == 0) {
							A.GenerateSeedsOnGarden(id, column_location_of_seed, string_location_of_seed);
						}
						else {
							std::cout << "Ошибка, поле занято!" << std::endl;
						}
						std::cout << "Поле:" << std::endl;
						A.GardenPrint();
						std::cout << std::endl;
						break;
					}


				case 4:
					std::cout << "4. Удалить растение с грядки." << std::endl;
					std::cout << "Введите ячейку поля(строка)" << std::endl;
					std::cin >> column_location_of_seed;
					std::cout << "Введите ячейку поля(столбец)" << std::endl;
					std::cin >> string_location_of_seed;
					if (A.getArray()[column_location_of_seed - 1][string_location_of_seed - 1][0]) {
						A.DeleteSeedsOnGarden(column_location_of_seed, string_location_of_seed);

					}
					else {
						std::cout << "Ошибка, поле пустое" << std::endl;
					}
					std::cout << "Поле:" << std::endl;
					A.GardenPrint();
					std::cout << std::endl;
					break;

				case 5:
					std::cout << "5. Посадить своё уникальное растение." << std::endl;
					std::cout << "Введите ID растения:" << std::endl;
					std::cin >> id;
					if (id < 100) {
						std::cout << "Неверное значение, выберите снова." << std::endl;
						break;
					}
					std::cout << "Введите период полива:" << std::endl;
					std::cin >> watering;
					std::cout << "Введите ячейку поля(строка)" << std::endl;
					std::cin >> column_location_of_seed;
					std::cout << "Введите ячейку поля(столбец)" << std::endl;
					std::cin >> string_location_of_seed;

					if (string_location_of_seed <= 0 || column_location_of_seed <= 0) {
						std::cout << "Ошибка ввода значений!" << std::endl;
						break;
					}
					else {

						if (A.getArray()[column_location_of_seed - 1][string_location_of_seed - 1][0] == 0) {
							A.GenerateSeedsOnGarden(id, column_location_of_seed, string_location_of_seed);
						}
						else {
							std::cout << "Ошибка, поле занято!" << std::endl;
						}
						std::cout << "Поле:" << std::endl;
						A.GardenPrint();
						std::cout << std::endl;
						break;
					}
				case 6:
					std::cout << "6. Сбор урожая:" << std::endl;
					A.PrintGardenAfterHarvest();
					std::cout << std::endl;
					break;

				case 7:
					std::cout << "7. Запуск генератора засухи:" << std::endl;
					A.GenerateDroughtInGarden(1);
					std::cout << std::endl;
					break;
				case 8:

					std::cout << "8. Запустить симуляцию." << std::endl;
					A.Running(ValueDaysWeather, watering);
					A.ClearToVectors(ValueDaysWeather);
					break;

				default:
					break;

				}
			}
		}
	}
};

