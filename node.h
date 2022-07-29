#pragma once
//#include <iostream>
//#include <fstream>
#include "mcoord.h"
#include "my_err.h"

using namespace std;
using namespace MY_ENUM;

class node : public mcoord {
	int numb;
	char str[512];

public:

	node(int nb, char* st, double a, double b) {
		x = a;
		y = b;
		numb = nb;
		strcpy_s(str, st);
	}

	node() {
		x = 0;
		y = 0;
		numb = 0;
	}

	node(const node& ob) {
		x = ob.x;
		y = ob.y;
		numb = ob.numb;
		strcpy_s(str, ob.str);
	}

	~node() {

	}


	node& operator =(const node& ob) {
		x = ob.x;
		y = ob.y;
		numb = ob.numb;
		strcpy_s(str, ob.str);
		return *this;
	}



	friend ostream& operator << (ostream& strm, const node& ob) {
		strm << "Wierzcholek nr " << ob.numb << " o nazwie " << ob.str << " posiada wspolrzedne: x= " << ob.x << " y= " << ob.y << endl;
		return strm;
	}



	friend istream& operator >> (istream& strm, node& ob) {

		cout << "Podaj kolejo nr, nazwe, wsporzedne x i y\n";
		strm >> ob.numb >> ob.str >> ob.x >> ob.y;
		if (strm.fail()) {
			strm.clear();
			strm.ignore();
			new Errors(MY_EXCEPT_BAD_INPUT_TYPE_ERROR);
		}
		return strm;
	}

	friend fstream& operator << (fstream& strm, node* ob) {
		strm.write((const char*)ob, sizeof(node));
		return strm;
	}

	friend fstream& operator >> (fstream& strm, node* ob) {
		strm.read((char*)ob, sizeof(node));
		return strm;
	}



	bool operator == (const node& ob) const
	{
		return { numb == ob.numb };
	}

};
