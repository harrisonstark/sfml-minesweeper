#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Tile {
private:
	int mine = 0;
	int num = 0;
	Tile* tileList[8];
public:
	Tile(int mine);
	void setTileList(Tile* tileList[8], int index);
	int getMine();
};