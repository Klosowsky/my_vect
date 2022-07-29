#include "stdafx.h"
#include "interf.h"


void interf::push() {
    try {
        cin >> a;
        vect.push(a);
    }
    catch (Errors er) {
        er.except();
    }
}



void interf::pop() {
    try {
        cout << *vect.pop();
    }
    catch (Errors err) {
        err.except();
    }
}



void interf::delObj() {
    int inde;
    if (!vect.isEmpty()) {
        vect.show_all_with_ind();
        cout << "Podaj index obiektu do usuniecia\n";
        try {
            cin >> inde;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                new Errors(MY_EXCEPT_BAD_INPUT_TYPE_ERROR);
            }
            vect.erase(vect.get_by_index(inde));

        }
        catch (Errors er) {
            er.except();
        }


    }
}


void interf::clrAll() {
    vect.clear_all();
}


void interf::modifyObject() {
    if (!vect.isEmpty()) {
        int inde;
        vect.show_all_with_ind();
        cout << "Podaj index obiektu do zmodyfikowania\n";
        try {
            cin >> inde;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                new Errors(MY_EXCEPT_BAD_INPUT_TYPE_ERROR);
            }
            if (vect.chkInd(inde)) {
                cin >> a;
                vect.modifyObj(inde, a);
                new Errors(MY_EXCEPT_MOD_OBJ);
            }
        }
        catch (Errors er) {
            er.except();
        }
    }
}



void interf::findObj() {
    int nr_w;
    cout << "Podaj szukany nr wierzcholka" << endl;
    try {
        cin >> nr_w;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            new Errors(MY_EXCEPT_BAD_INPUT_TYPE_ERROR);
        }
        my_find(vect.get_begin(), vect.get_end(), node(nr_w, (char*)"", 0, 0));
    }
    catch (Errors er) {
        er.except();
    }
}

void interf::shwAll() {
    vect.show_all();
}


void interf::saveToBin() {
    if (!fbin.is_open()) {
        new Errors(MY_EXCEPT_OPEN_FILE_ERROR);
    }
    else {
        fbin << vect;
    }
}

void interf::readFromBin() {
    if (!fbin.is_open()) {
        new Errors(MY_EXCEPT_OPEN_FILE_ERROR);
    }
    else {
        fbin >> vect;
    }
}




interf::interf() {
    char filepath[256];
    _searchenv("filebin.bin", "PATH", filepath);
    if (filepath[0] == '\0') {
        ofstream tmpfbin("filebin.bin");
        tmpfbin.close();
    }
    fbin.open("filebin.bin", ios_base::in | ios_base::out);
    if (!fbin.is_open()) {
        new Errors(MY_EXCEPT_OPEN_FILE_ERROR);
    }

}
interf::~interf() {
    fbin.close();
}