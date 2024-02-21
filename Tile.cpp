#include "Tile.h"

Tile::Tile(int mine) {
	this->mine = mine;
}

void Tile::setTileList(Tile* tileList[8], int index) {
	for (int i = 0; i < 8; i++) {
		this->tileList[i] = tileList[i];
		num += (tileList[i] != nullptr) ? tileList[i]->mine : 0;
	}
	cout << num << " ";
	if (index == 24) {
		cout << endl;
	}
}

int Tile::getMine() {
	return mine;
}