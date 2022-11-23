#pragma once

class Tree
{
private:
	int ID_tree = 1111;

public:

	int get_ID_tree() {
		return ID_tree;
	}

	void ChangeGarden(int*** array, int x, int y) {
		array[x][y][0] = get_ID_tree();
	}

	void getHarvestOfTrees(int*** array, int x, int y) {
		array[x][y][4] = get_ID_tree();
	}
};