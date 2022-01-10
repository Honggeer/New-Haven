//
// Created by Kunming Yang on 2020-01-22.
//

#include "GBMapLoader.h"
#include <sstream>
#include <algorithm>



GBMapLoader::GBMapLoader()
{
	map = new GBMap();
}

GBMapLoader::~GBMapLoader()
{
	delete map;
}

void GBMapLoader::readfromfile(std::string filename)
{
	//variable
	ifstream input(filename);           //file
	string line = "";                   //current line
	string word = "";

	int flag = 0;                       //flags
	int i = 0;                          //counter


										//Tile
	string ul = "";
	string ur = "";
	string dl = "";
	string dr = "";

	//Boarder
	int id = 0,
		id_first = 0,
		id_second = 0,
		id_third = 0,
		id_fourth = 0,
		id_in;
	if (input.fail()) {
		cout << "Failed to open the specified file: " << filename << endl;
		//-- If not, stop the program.
		//system("pause");
		exit(1);
	}
	//read file
	while (getline(input, line))
	{
		line.erase(remove(line.begin(), line.end(), '\r'), line.end());

		//empty line or comment line, do nothing
		if (line == "" || line.at(0) == ';')
		{
			// nothing happen
		}

		else
		{
			if (line.at(0) == '[' && line.at(line.length() - 1) == ']')
			{
				//set flag = 1, when read boarders.
				if (line == "[tiles]")
				{
					if (flag == 0)
					{
						flag = 1;
					}
					else
						error_m();
				}
				//set flag = 2, when read tile.
				else if (line == "[borders]")
				{
					if (flag == 1)
						flag = 2;
					else
						error_m();
				}
				
			}
			else
			{
				istringstream iss(line);
				//Boarders section
				//11 12 21 ; tileid - adjacent tiles
				if (flag == 2)
				{
					iss >> id;
					iss >> id_first;
					iss >> id_second;
					iss >> id_third;
					iss >> id_fourth;

					map->SearchById(id)->addAdjacentTileSlot(map->SearchById(id_first));
					map->SearchById(id)->addAdjacentTileSlot(map->SearchById(id_second));
					map->SearchById(id)->addAdjacentTileSlot(map->SearchById(id_third));
					map->SearchById(id)->addAdjacentTileSlot(map->SearchById(id_fourth));

					//iss >> word;
					
					//id = stoi(word);
					//if (id > map->getTileSlots().size())
					//	error_m();
					//if (map->getTileSlots().at(id)->getAdjacentTileSlots().size() != 0)
					//	error_m(); //check duplicate adj declaration
					//while (iss >> word) {		// read word
					//	
					//	if (stoi(word) > map->getTileSlots().size())
					//		error_m(); // if BuildingSlot_id is not in vector of BuildingSlot, then error
					//	if (id == stoi(word))
					//		error_m(); // check if BuildingSlot is adj to self

					//	map->getTileSlots().at(id)->addAdjacentTileSlot(map->getTileSlots().at(stoi(word)));
					//}
					//id++;
					//while (iss >> id_in)
					//{
					//	if (map->SearchById(id_in)->getTileSlotId() == 0)
					//	{
					//		map->addTileSlot(new TileSlot(id_in));
					//	}
					//}
				}
				//Tile Section
				//11 sheelp stone sheep wheat; tileid - upleft - upright - downleft - downright
				else if (flag == 1)
				{
					iss >> id;
					iss >> ul;
					iss >> ur;
					iss >> dl;
					iss >> dr;
					
					if (ul == "") {
						TileSlot* ts = new TileSlot(id);
						map->addTileSlot(ts);
					}
					else {
						Tile* temp = new Tile(sToTypes(ul), sToTypes(ur), sToTypes(dl), sToTypes(dr));
						TileSlot* ts = new TileSlot(temp, id);
						map->addTileSlot(ts);
					}
					
					ul ="";
					ur ="";
					dl ="";
					dr ="";

				}

			}
		}
	}
	input.close();
}

void GBMapLoader::error_m()
{
	cout << "Error - unexpected value was found in the program." << endl;
	//system("pause");
	exit(1);
}

GBMap * GBMapLoader::getMap()
{
	return map;
}

void GBMapLoader::setMap(GBMap *GBMap_)
{
	this->map = GBMap_;
}
