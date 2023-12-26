#include "adt.h"
#include "menu.h"
#include "utilities.h"

using namespace std;

int main() {
    list_organisasi L1;
    list_mahasiswa L2;
    list_prestasi L3;
    string input;

    create_list_organisasi(L1);
    create_list_mahasiswa(L2);
    create_list_prestasi(L3);

    while (true) {
        clear_screen();
        print_prompt_main_menu();
        cout << "Pilih [1/2/3/4]: ";
        cin >> input;

        if (input == "1") {
            menu_organisasi(L1, L2);
        } else if (input == "2") {
            menu_mahasiswa(L2, L3);
        } else if (input == "3") {
            menu_prestasi(L3);
        } else if (input == "4") {
            break;
        } else {
            // TODO
            // cetak "salah input!"
            wait_for_enter();
        }
    }

    clear_screen();
    cout << "bye" << endl;

    return 0;
}
