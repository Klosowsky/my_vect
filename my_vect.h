#pragma once

#pragma once
#pragma warning(disable : 4996)
//#include <iostream>
//#include <fstream>
#include "my_err.h"
#include "windows.h"
#include "node.h"

using namespace std;
using namespace MY_ENUM;

template <class T> class my_vect
{
	T* dat;
	size_t ndim;
	size_t last;
public:
	my_vect(size_t dim);
	my_vect() : dat(NULL), ndim(0), last(0) {}
	my_vect(const my_vect& ob);
	~my_vect();
	T* get_begin();
	T* get_end();
	void push(const T& ob);
	T* pop();
	void erase(T* ob);
	void clear_all();
	void show_all();
	void show_all_with_ind();
	T* get_by_index(size_t ind);
	void packArray(int index);
	void modifyObj(size_t ind, const T& ob);
	bool isEmpty();
	bool chkInd(int ind);

	template<class T>
	friend fstream& operator<<(fstream& out, my_vect<T>& v);
	template<class T>
	friend fstream& operator>>(fstream& in, my_vect<T>& v);

	T& operator [](const size_t ind) {
		return dat[ind];
	}

private:
	void realloc();
};


template<class T>
fstream& operator<<(fstream& filbin, my_vect<T>& ob) {
	size_t it;
	filbin.clear();
	filbin.close();
	filbin.open("filebin.bin", ios_base::in | ios_base::out | ios_base::trunc);
	if (!filbin.is_open()) {
		new Errors(MY_EXCEPT_OPEN_FILE_ERROR);
	}
	for (T* tmp = ob.get_begin(); tmp < ob.get_end(); tmp++) {
		filbin << tmp;
		if (filbin.bad() || filbin.fail()) {
			new Errors(MY_EXCEPT_WRITE_FILE_ERROR);
		}
	}
	new Errors(MY_EXCEPT_SAVE_TO_FILE_ST);
	return filbin;
}

template<class T>
fstream& operator>>(fstream& filbin, my_vect<T>& ob) {
	ob.last = 0;
	T tmp;
	filbin.clear();
	filbin.seekg(0);
	while (!filbin.eof()) {
		filbin >> &tmp;
		if (filbin.bad()) {
			new Errors(MY_EXCEPT_READ_FILE_ERROR);
		}
		if (filbin.eof()) {
			break;
		}
		ob.push(tmp);
	}
	new Errors(MY_EXCEPT_READ_FROM_FILE_ST);
	return filbin;
}


template <class T> my_vect<T> ::my_vect(size_t dim)
{
	ndim = dim;
	try {
		dat = new T[ndim];
	}
	catch (bad_alloc)
	{
		new Errors(MY_EXCEPT_ALLOC_MEM_ERROR);
	}
	last = 0;
}


template <class T> my_vect<T>::~my_vect()
{
	if (dat) {
		delete[] dat;
	}
	dat = NULL;
}


template <class T>
inline T* my_vect<T>::get_begin() {
	return dat;
}


template <class T>
inline T* my_vect<T>::get_end() {
	if (dat) {
		return &dat[last];
	}
	else {
		return NULL;
	}
}


template <class T>
void my_vect<T>::push(const T& ob)
{
	if (last >= ndim) {
		realloc();
	}
	dat[last] = ob;
	last++;
}

template <class T> T* my_vect<T> ::pop()
{
	if (last > 0)
	{
		last--;
		return &dat[last];
	}
	else
	{
		new Errors(MY_EXCEPT_NULL_POINTER_ERROR);
		return NULL;
	}
}


template<class T> void my_vect<T>::erase(T* ob) {
	int ind = 0;
	T* tmp = get_begin();
	for (; tmp < get_end(); tmp++) {
		if (ob == tmp) {
			cout << *tmp;
			break;
		}
		ind++;
	}
	packArray(ind);
}

template <class T> inline void my_vect<T>::realloc() {
	try {
		if (last >= ndim) {
			T* tmp = new T[2 * ndim];
			copy(get_begin(), get_end(), tmp);
			delete[] dat;
			dat = tmp;
			ndim *= 2;
		}
	}
	catch (bad_alloc) {
		new Errors(MY_EXCEPT_ALLOC_MEM_ERROR);
	}
}


template<class T>
void my_vect<T>::packArray(int index) {
	for (int i = index; i < last - 1; i++) {
		dat[i] = dat[i + 1];
	}
	last--;
}

template<class T> void my_vect<T>::clear_all() {
	last = 0;
	new Errors(MY_EXCEPT_CLR_ALL);
}


template<class T> void my_vect<T>::show_all() {
	if (last > 0) {
		for (int i = 0; i < last; i++) {
			cout << dat[i];
		}
	}
	else {
		new Errors(MY_EXCEPT_EMPTY_ARRAY);
	}
}


template<class T> void my_vect<T>::show_all_with_ind() {
	if (last > 0) {
		for (int i = 0; i < last; i++) {
			cout << "Index [" << i << "]: " << dat[i];
		}
	}
	else {
		new Errors(MY_EXCEPT_EMPTY_ARRAY);
	}
}


template<class T>
void my_vect<T>::modifyObj(size_t ind, const T& ob) {
	dat[ind] = ob;
}


template <class T>
inline T* my_vect<T>::get_by_index(size_t ind) {
	if (ind >= last) {
		new Errors(MY_EXCEPT_BAD_INDEX);
		return NULL;
	}
	return &dat[ind];
}


template <class T>
inline bool my_vect<T>::isEmpty() {
	if (last == 0) {
		new Errors(MY_EXCEPT_EMPTY_ARRAY);
		return true;
	}
	else {
		return false;
	}
}


template <class T>
inline bool my_vect<T>::chkInd(int ind) {
	if (ind < last) {
		return true;
	}
	else {
		new Errors(MY_EXCEPT_BAD_INDEX);
		return false;
	}
}


template <class T, class Key>
T* my_find(const T* p_begin, const T* p_end, const Key& k) {
	if (p_begin > p_end) {
		return NULL;
	}
	const T* tmp = p_begin;
	for (; tmp != p_end; tmp++) {
		if (*tmp == k) {
			cout << *tmp;

			my_find(tmp + 1, p_end, k);
			return const_cast<T*>(tmp);
		}
	}
	return NULL;
}

