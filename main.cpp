#include "adt.h"
#include "menu.h"
#include "utilities.h"

#include <iostream>

using namespace std;

int main() {
    list_organisasi LO;
    list_mahasiswa LM;
    string input;

    clear_screen();
    validate_repeat(input, "Pakai Data Dummy? [Y/N]: ");

    if (input == "Y" || input == "y") {
        use_dummy_data(LO, LM);
    } else {
        create_list_organisasi(LO);
        create_list_mahasiswa(LM);
    }

    while (true) {
        clear_screen();
        print_prompt_main_menu();
        cout << "Pilih [1/2/3]: ";
        cin >> input;
        cout << endl;

        if (input == "1") {
            menu_organisasi(LO, LM);
        } else if (input == "2") {
            menu_mahasiswa(LO, LM);
        } else if (input == "3") {
            break;
        } else {
            cout << WRONG_INPUT_PROMPT << endl;
            wait_for_enter();
        }
    }

    clear_screen();
    cout << "bye" << endl;
    cout << endl;

    return 0;
}
