
#include "VGMapLoader.h"
#include <sstream>
#include <algorithm>

VGMapLoader::VGMapLoader()
{
	vgmap = new VGMap();
}

VGMapLoader::VGMapLoader(string name)
{
	vgmap = new VGMap(name);
}


VGMapLoader::~VGMapLoader()
{
	delete vgmap;
}

void  VGMapLoader::readfromfile(string myfilename)
{

	


	//// variables
	ifstream input(myfilename);		// file stream
	// << myfilename << endl;
	string line = "",				// current line
		word = "";				// current word within line

	int flag = 0,					// section flag			
		i = 0;					// incrementing index for words within line


	int BuildingSlot_ID = 0;		// BuildingSlot_ID 
	int	   Points = 0;			// Number of points
	int address = 0;
	// Borders
	int border_id = 0;				//  id in border section

	if (input.fail()) {
		cout << "Failed to open the specified file: " << myfilename << endl;
		//-- If not, stop the program.
		//system("pause");
		exit(1);
	}

	while (getline(input, line))	// read the file
	{

		line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); //remove "\r"

		if (line == "" || line.at(0) == ';') {	// empty line or comment ;
												// do nothing
		}
		else
		{
			// separate sections according to header. Order matters
			if (line.at(0) == '[' && line.at(line.length() - 1) == ']')
			{
				if (line == "[BuildingSlots]") {
					if (flag == 0) flag = 1;
					else error_m();
				}

				else if (line == "[borders]") {
					if (flag == 1) flag = 2;
					else error_m();
				}
				else flag = 0;
			}
			else
			{
				istringstream iss(line);

				/* Building Slot section */
				// 11 1 <~~Id of the building Slot- Number of points


				if (flag == 1)
				{

					while (iss >> word) {		// read word
						i = i + 1;
						if (i == 1) {			// address
							has_only_digits_err(word, line);
							address = stoi(word);
						}

						else if (i == 2)	// BuildinSlotg_id
						{
							has_only_digits_err(word, line);
							BuildingSlot_ID = stoi(word);

						}
						else if (i == 3)	// Points
						{
							has_only_digits_err(word, line);
							Points = stoi(word);

						}
					}

					i = 0;
					//cout << "Failed to open the specified file: " << myfilename << endl;
					vgmap->addBuildingSlot(new BuildingSlot(Points, BuildingSlot_ID));

				}
				/* Borders section */
				// 1 2 3 38 <~~number of the BuildingSlot - what BuildingSlots that BuildingSlot is adjacent to
				else if (flag == 2)
				{


					iss >> word;
					has_only_digits_err(word, line);
					border_id = stoi(word);
					if (border_id > vgmap->getBuildingSlots().size())
						error_m();
					if (vgmap->getBuildingSlots().at(border_id - 1)->getAdjacentBuildingSlots().size() != 0)
						error_m(); //check duplicate adj declaration
					while (iss >> word) {		// read word
						has_only_digits_err(word, line);
						if (stoi(word) > vgmap->getBuildingSlots().size())
							error_m(); // if BuildingSlot_id is not in vector of BuildingSlot, then error
						if (border_id == stoi(word))
							error_m(); // check if BuildingSlot is adj to self

						vgmap->getBuildingSlots().at(border_id - 1)->addAdjacentBuildingSlots(vgmap->getBuildingSlots().at(stoi(word) - 1));
					}
				}
			}
		}
	}
	input.close();
	//graphCorrectness();
}

void VGMapLoader::has_only_digits_err(const string s, const string line) {
	if (s.find_first_not_of("0123456789") != string::npos)
	{
		cout << "Error Digit - the line \"" << line << "\" contains an unexpected item: " << s << endl;
		//system("pause");
		exit(1);
	}
}

void VGMapLoader::error_m() {
	cout << "Error - unexpected value was found in the program." << endl;
	//system("pause");
	exit(1);
}

VGMap* VGMapLoader::getVGMap() {
	return vgmap;
}

void VGMapLoader::setVGMap(VGMap *vgmap) {
	this->vgmap = vgmap;
}

