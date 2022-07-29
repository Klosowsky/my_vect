#pragma once
#include "stdafx.h"
//#include <iostream>
//#include <fstream>

class mcoord
{
protected:
	double x;
	double y;
public:
	mcoord(double xx, double yy) { x = xx; y = yy; }
	mcoord() { x = 0; y = 0; }
};
