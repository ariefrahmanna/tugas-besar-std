#include "adt.h"
#include "menu.h"
#include "utilities.h"

using namespace std;

int main() {
    list_organisasi LO;
    list_mahasiswa LM;

    string input;

    create_list_organisasi(LO);
    create_list_mahasiswa(LM);

    while (true) {
        clear_screen();
        print_prompt_main_menu();
        cout << "Pilih [1/2/3]: ";
        cin >> input;

        if (input == "1") {
            menu_organisasi(LO, LM);
        } else if (input == "2") {
            menu_mahasiswa(LM);
        } else if (input == "3") {
            break;
        } else {
            wait_for_enter();
        }
    }

    clear_screen();
    cout << "bye" << endl;

    return 0;
}
