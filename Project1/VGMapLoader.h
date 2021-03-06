#pragma once

#include "VGMap.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



class VGMapLoader
{
private:
	VGMap * vgmap;

public:

	VGMapLoader();

	VGMapLoader(string name);

	virtual ~VGMapLoader();

	virtual void readfromfile(string myfilename);

	void has_only_digits_err(const string s, const string line);

	void error_m();

	VGMap* getVGMap();

	void setVGMap(VGMap *vgmap);
};

