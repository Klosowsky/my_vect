#include "my_err.h"
#include "node.h"
#include "interf.h"

using namespace std;
using namespace MY_ENUM;

namespace MENU {
    enum MY_ENUM_MENU {
        ADD_OBJ,
        GET_LAST_OBJ,
        DEL_OBJ,
        DEL_ALL,
        MODIFY_OBJ,
        FIND_OBJ,
        SAVE_DATA,
        READ_DATA,
        SHOW_DATA,
        END,
    };
}

int _tmain(int argc, _TCHAR* argv[])
{

    int choose;
    bool cnt = true;

    try {
        interf interfc;
        while (cnt) {
            Errors info(MY_EXCEPT_MENU_STATEMENT);
            try {
                cin >> choose;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    new Errors(MY_EXCEPT_BAD_INPUT_TYPE_ERROR);
                }
            }
            catch (Errors er) {
                er.except();
                continue;
            }
            switch (choose) {
            case MENU::ADD_OBJ:
                interfc.push();
                break;
            case  MENU::GET_LAST_OBJ:
                interfc.pop();
                break;
            case  MENU::DEL_OBJ:
                interfc.delObj();
                break;
            case  MENU::DEL_ALL:
                interfc.clrAll();
                break;
            case  MENU::MODIFY_OBJ:
                interfc.modifyObject();
                break;
            case  MENU::FIND_OBJ:
                interfc.findObj();
                break;
            case  MENU::SAVE_DATA:
                interfc.saveToBin();
                break;
            case  MENU::READ_DATA:
                interfc.readFromBin();
                break;
            case  MENU::SHOW_DATA:
                interfc.shwAll();
                break;
            case  MENU::END:
                new Errors(MY_EXCEPT_THE_END);
                cnt = false;
                break;
            default:
                new Errors(MY_EXCEPT_WRONG_CODE);
                break;
            }
        }
    }
    catch (Errors err) {
        cnt = false;
        err.except();
    }
}

