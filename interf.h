#pragma once
//#include "stdafx.h"
//#include <iostream>
#include "my_vect.h"
//#include "my_err.h"
#include "node.h"


class interf {
	size_t dim = 3;
	node a;
	my_vect<node> vect = my_vect<node>(dim);

public:
	fstream fbin;
	interf();
	~interf();
	void push();
	void pop();
	void delObj();
	void clrAll();
	void modifyObject();
	void findObj();
	void saveToBin();
	void readFromBin();
	void shwAll();
};


