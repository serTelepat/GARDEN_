#pragma once
#include "Garden.h"
#include "Weather.h"

class Sun
{
private:
	int DaySun = 1;

public:

	void PrintSun(int numb) {
		std::cout << "���� " << numb << " - ���������!" << std::endl;
	}

	int get_DaySun() {
		return DaySun;
	}
};