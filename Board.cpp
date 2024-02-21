#include "Board.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Board::generateBoard() {
	int numM = 0;
	for(int i = 0; i < height; i++){
		vector<Tile> vt;
		for (int h = 0; h < width; h++) {
				vt.push_back(Tile(0));
		}
		tiles.push_back(vt);
	}
	while (numM != countM) {
		int rX = rand() % this->width;
		int rY = rand() % this->height;
		int mine = tiles[rY][rX].getMine();
		tiles[rY][rX] = Tile(1);
		if (mine == 0) {
			numM++;
		}
	}
	for (int i = 0; i < height; i++) {
		for (int h = 0; h < width; h++) {
			Tile* tileList[8];
			tileList[0] = (i - 1 < 0 || h - 1 < 0) ? nullptr : &tiles[i - 1][h - 1];
			tileList[1] = (i - 1 < 0) ? nullptr : &tiles[i - 1][h];
			tileList[2] = (i - 1 < 0 || h + 1 > width - 1) ? nullptr : &tiles[i - 1][h + 1];
			tileList[3] = (h + 1 > width - 1) ? nullptr : &tiles[i][h + 1];
			tileList[4] = (i + 1 > height - 1 || h + 1 > width - 1) ? nullptr : &tiles[i + 1][h + 1];
			tileList[5] = (i + 1 > height - 1) ? nullptr : &tiles[i + 1][h];
			tileList[6] = (i + 1 > height - 1 || h - 1 < 0) ? nullptr : &tiles[i + 1][h - 1];
			tileList[7] = (h - 1 < 0) ? nullptr : &tiles[i][h - 1];
			tiles[i][h].setTileList(tileList, h);
		}
	}
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int h = 0; h < width; h++) {
			cout << tiles[i][h].getMine() << " ";
		}
		cout << endl;
	}
}

Board::Board() {
	fstream inFile("../boards/config.cfg");
	string s = "";
	getline(inFile, s);
	this->width = stoi(s);
	getline(inFile, s);
	this->height = stoi(s);
	getline(inFile, s);
	this->countM = stoi(s);
	this->countT = this->width * this->height;
	this->generateBoard();
}