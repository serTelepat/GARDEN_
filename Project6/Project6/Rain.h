#pragma once
#include "Weather.h"

class Rain

{
private:
	int DayRain = 3;

public:
	int get_DayRain() {
		return DayRain;
	}
	void PrintDayRain(int numb) {
		std::cout << "� ���� " << numb << " ��� �����" << std::endl;
	}
};