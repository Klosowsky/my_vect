#include "stdafx.h"
#include "my_err.h"

using namespace MY_ENUM;
using namespace std;


const char* Errors::tab_err[] =
{
	"E Memory allocation error",
	"E Open file error",
	"E Write file error",
	"E Read file error",
	"E Access file error",
	"E Wrong type error",
	"E Brak elementu w tablicy",
	"S Podaj kod operacji \n0 - Dodaj obiekt\n1 - Pobierz ostatni obiekt\n2 - Usun obiekt\n3 - Usun wszystko\n4 - Zmodyfikuj obiekt\n5 - Znajdz wszystkie obiekty\n6 - Zapisz dane na dysk\n7 - Odczytaj dane z dysku\n8 - Wyswietl dane na monitorze\n9 - Zakoncz",
	"S Zapisano dane do pliku",
	"S Wczytano dane z pliku",
	"S Koniec",
	"S Zmodyfikowano obiekt",
	"S Nie znaleziono obiektu",
	"S Usunieto wszystkie obiekty",
	"W Tablica jest pusta",
	"W Podano zly kod",
	"W Podano zly index",
};

Errors::Errors(enum MY_ENUM::ERROR_ENUM my_enum) {
	num = my_enum;
	if (tab_err[num][0] == 'E') {
		throw* this;
	}
	else {
		except();
	}
}
Errors::~Errors() {
}

void Errors::except() {
	cout << tab_err[num] + 2 << endl;
}
