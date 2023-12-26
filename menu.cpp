#include "menu.h"

void menu_organisasi(list_organisasi &LP, list_mahasiswa &LC) {
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi();
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            info_organisasi org;
            cout << "Masukkan data Organisasi" << endl;
            cout << "ID             : " ;
            cin >> org.id;
            cout << "Nama           : " ;
            cin >> org.nama;
            cout << "Bidang         : " ;
            cin >> org.bidang;
            cout << "Tahun Berdiri  : " ;
            cin >> org.sejak_tahun;
            if(search_organisasi(LP, org.id) != NULL){
                cout << "!!! ORGANISASI SUDAH TERDATA !!!" << endl;
            }else{
                insert_last_organisasi(LP, create_elm_organisasi(org));
                cout << "=== ORGANISASI BERHASIL DITAMBAHKAN ===" << endl;
            }


        } else if (input == "2") {
            adr_organisasi p;
            string NIM_anggota, id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            while(search_organisasi(LP, id_organisasi)==NULL){
                cout << "!!! ID ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }
            cout << "Masukkan NIM anggota   : ";
            cin >> NIM_anggota;
            while(search_mahasiswa(LC, NIM_anggota)==NULL){
                cout << "!!! NIM TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan NIM anggota : ";
                cin >> NIM_anggota;
            }

            p = search_organisasi(LP, id_organisasi);
            insert_anggota(LC, p, NIM_anggota);
            if(search_anggota(p, NIM_anggota) != NULL){
                cout << "!!! ANGGOTA SUDAH TERDATA !!!" << endl;
            }else{
                insert_anggota(LC, p, NIM_anggota);
                cout << "=== ORGANISASI BERHASIL DITAMBAHKAN ===" << endl;
            }
            cout << "=== ANGGOTA BERHASIL DITAMBAHKAN ===" << endl;


        } else if (input == "3") {
            string id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            adr_organisasi p = search_organisasi(LP, id_organisasi);
            if(p == NULL){
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            }else{
                cout << "========   DATA ORGANISASI    ========" << endl;
                cout << "ID             :" << p->info.id << endl;
                cout << "NAMA           :" << p->info.nama << endl;
                cout << "BIDANG         :" << p->info.bidang << endl;
                cout << "TAHUN BERDIRI  :" << p->info.bidang << endl;
                cout << "======================================" << endl;

            }


        } else if (input == "4") {
            string NIM_anggota, id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            cout << "Masukkan NIM Anggota : ";
            cin >> NIM_anggota;
            adr_anggota q = search_anggota(search_organisasi(LP, id_organisasi), NIM_anggota);
            if(q == NULL){
                cout << "!!! ANGGOTA TIDAK DITEMUKAN !!!" << endl;
            }else{
                cout << "========    DATA ANGGOTA     ========" << endl;
                cout << "NIM        :" << q->value->info.nim << endl;
                cout << "NAMA       :" << q->value->info.nama << endl;
                cout << "JURUSAN    :" << q->value->info.jurusan << endl;
                cout << "GENDER     :" << q->value->info.gender << endl;
                cout << "ANGKATAN   :" << q->value->info.angkatan << endl;
                cout << "=====================================" << endl;

            }


        } else if (input == "5") {
            adr_organisasi temp;
            string id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            while(search_organisasi(LP, id_organisasi)== NULL){
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }
            temp = delete_organisasi(LP, id_organisasi);
            cout << "DATA ORGANISASI BERHASIL DIHAPUS" << endl;


        } else if (input == "6") {
            adr_anggota temp;
            string id_organisasi, NIM_anggota;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            while(search_organisasi(LP, id_organisasi)== NULL){
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }
            cout << "Masukkan NIM Anggota : ";
            cin >> NIM_anggota;
            while(search_organisasi(LP, id_organisasi)== NULL){
                cout << "!!! ANGGOTA TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan NIM Anggota : ";
                cin >> NIM_anggota;
            }
            temp = delete_anggota(search_organisasi(LP, id_organisasi), NIM_anggota);
            cout << "DATA ANGGOTA BERHASIL DIHAPUS" << endl;


        } else if (input == "7") {
            show_all_organisasi(LP);


        } else if (input == "8") {
            string id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            while(search_organisasi(LP, id_organisasi)== NULL){
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }
            show_mahasiswa(search_organisasi(LP, id_organisasi));


        } else if (input == "9") {
            cout << "Jumlah Organisasi adalah " << count_organisasi(LP);

        } else if (input == "10") {
            string id_organisasi;
            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            while(search_organisasi(LP, id_organisasi)== NULL){
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
                cout << "Masukkan ID Organisasi : ";
                cin >> id_organisasi;
            }
            cout << "Jumlah Anggota Organisasi adalah " << count_anggota(search_organisasi(LP, id_organisasi)) << endl;


        } else if (input == "11") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }
}

void menu_mahasiswa(list_mahasiswa &LP, list_prestasi &LC) {
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi();
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            //insert data mahasisiwa
        } else if (input == "2") {
            //insert data peraih
        } else if (input == "3") {
            //search data mahasiswa
        } else if (input == "4") {
            //search data peraih
        } else if (input == "5") {
            //delete data mahasisiwa
        } else if (input == "6") {
            //delete data peraih
        } else if (input == "7") {
            //show data peraih
        } else if (input == "8") {
            //show data peraih
        } else if (input == "9") {
            //hitung jumlah mahasisiwa
        } else if (input == "10") {
            //hitung jumlah peraih
        } else if (input == "11") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }
}

void menu_prestasi(list_prestasi &L) {
    string input;
    while(true){
        clear_screen();
        print_prompt_menu_organisasi();
        cout << "Pilih: ";
        cin >> input;
        if (input == "1") {
            //insert data prestasi
        } else if (input == "2") {
            //search data prestasi
        } else if (input == "3") {
            //delete data prestasi
        } else if (input == "4") {
            //show data prestasi
        } else if (input == "5") {
            //hitung jumlah prestasi
        } else if (input == "6") {
            break;
        } else {
            // TODO
            cout << "!!!    INPUT SALAH    !!!" << endl;
            wait_for_enter();
        }
    }

}

void print_prompt_main_menu(){
    cout << "=============  MAIN MENU   =============" << endl;
    cout << "PILIH LIST: " << endl;
    cout << "1. ORGANISASI" << endl;
    cout << "2. MAHASISWA" << endl;
    cout << "3. PRESTASI" << endl;
    cout << "4. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_organisasi(){
    cout << "=============  ORGANISASI  =============" << endl;
    cout << "1. INSERT DATA ORGANISASI" << endl;
    cout << "2. INSERT DATA ANGGOTA" << endl;
    cout << "3. SEARCH DATA ORGANISASI" << endl;
    cout << "4. SEARCH DATA ANGGOTA" << endl;
    cout << "5. DELETE DATA ORGANISASI" << endl;
    cout << "6. DELETE DATA ANGGOTA" << endl;
    cout << "7. SHOW DATA ORGANISASI" << endl;
    cout << "8. SHOW DATA ANGGOTA" << endl;
    cout << "9. HITUNG JUMLAH ORGANISASI" << endl;
    cout << "10. HITUNG JUMLAH ANGGOTA" << endl;
    cout << "11. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_mahasiswa(){
    cout << "=============  MAHASISWA  =============" << endl;
    cout << "1. INSERT DATA MAHASISWA" << endl;
    cout << "2. INSERT DATA PERAIH PRESTASI" << endl;
    cout << "3. SEARCH DATA MAHASISWA" << endl;
    cout << "4. SEARCH DATA PERAIH PRESTASI" << endl;
    cout << "5. DELETE DATA MAHASISWA" << endl;
    cout << "6. DELETE DATA PERAIH PRESTASI" << endl;
    cout << "7. SHOW DATA MAHASISWA" << endl;
    cout << "8. SHOW DATA PERAIH PRESTASI" << endl;
    cout << "9. HITUNG JUMLAH MAHASISWA" << endl;
    cout << "10. HITUNG JUMLAH PERAIH PRESTASI" << endl;
    cout << "11. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_prestasi(){
    cout << "=============  PRESTASI  =============" << endl;
    cout << "1. INSERT DATA PRESTASI" << endl;
    cout << "2. SEARCH DATA PRESTASI" << endl;
    cout << "3. DELETE DATA PRESTASI" << endl;
    cout << "4. SHOW DATA PRESTASI" << endl;
    cout << "5. HITUNG JUMLAH PRESTASI" << endl;
    cout << "6. EXIT" << endl;
    cout << "========================================" << endl;
}
