#pragma once
#include <vector>
#include "Tile.h"
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;

class Board {
private:
	int width = 0;
	int height = 0;
	int countM = 0;
	int countT = 0;
	vector<vector<Tile>> tiles;
	map<string, sf::Sprite> sprites;
	map<string, sf::Texture> textures;
	vector<string> images = { "debug","digits","face_happy","face_lose","face_win","flag",
							 "mine","test_1","test_2","test_3","tile_hidden","tile_revealed",
							 "number_1","number_2","number_3","number_4",
							 "number_5","number_6","number_7","number_8" };
public:
	void generateBoard();
	Board();
};