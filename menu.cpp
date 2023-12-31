#include "menu.h"

void menu_organisasi(list_organisasi &LO, list_mahasiswa &LM) {
    string input, nim, id_organisasi;
    info_organisasi info;
    adr_organisasi p;
    adr_anggota q;
    int n;

    while (true) {
        clear_screen();
        print_prompt_menu_organisasi();
        cout << "Pilih: "; cin >> input;
        cout << endl;

        if (input == "1") {     // insert data organisasi
            cout << "Masukkan data Organisasi" << endl;
            cout << "ID             : " ; cin >> info.id;
            cout << "Nama           : " ; cin >> info.nama;
            cout << "Bidang         : " ; cin >> info.bidang;
            cout << "Tahun Berdiri  : " ; cin >> info.sejak_tahun;
            cout << endl;

            if (search_organisasi(LO, info.id) != NULL) {
                cout << "!!! ORGANISASI SUDAH TERDATA !!!" << endl;
            } else {
                insert_last_organisasi(LO, create_elm_organisasi(info));
                cout << "=== ORGANISASI BERHASIL DITAMBAHKAN ===" << endl;
            }

        } else if (input == "2") {      // insert data anggota
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : "; cin >> id_organisasi;
            cout << "Masukkan NIM anggota   : "; cin >> nim;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);
            q = search_anggota(p, nim);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DAPAT DITEMUKAN !!!" << endl;
            } else if (search_mahasiswa(LM, nim) == NULL) {
                cout << "!!! MAHASISWA TIDAK DAPAT DITEMUKAN !!!" << endl;
            } else if (q != NULL) {
                cout << "!!! ANGGOTA SUDAH TERDATA !!!" << endl;
            } else {
                insert_anggota(LM, p, nim);
                cout << "=== ANGGOTA BERHASIL DITAMBAHKAN ===" << endl;
            }

        } else if (input == "3") {      // search data organisasi
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : "; cin >> id_organisasi;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "========   DATA ORGANISASI    ========" << endl;
                show_organisasi(p);
                cout << "======================================" << endl;
                cout << endl;
            }

        } else if (input == "4") {      // search data anggota
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            cout << "Masukkan NIM Anggota : ";
            cin >> nim;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);
            q = search_anggota(p, nim);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else if (q == NULL) {
                cout << "!!! ANGGOTA TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "========    DATA ANGGOTA     ========" << endl;
                cout << "NIM        :" << q->value->info.nim << endl;
                cout << "NAMA       :" << q->value->info.nama << endl;
                cout << "JURUSAN    :" << q->value->info.jurusan << endl;
                cout << "GENDER     :" << q->value->info.gender << endl;
                cout << "ANGKATAN   :" << q->value->info.angkatan << endl;
                cout << "=====================================" << endl;
                cout << endl;
            }

        } else if (input == "5") {      // delete data organisasi
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            cout << endl;

            p = delete_organisasi(LO, id_organisasi);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "=== DATA ORGANISASI BERHASIL DIHAPUS ===" << endl;
            }

        } else if (input == "6") {      // delete data anggota
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : "; cin >> id_organisasi;
            cout << "Masukkan NIM Anggota : "; cin >> nim;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);
            q = delete_anggota(p, nim);

            cout << "DATA ANGGOTA BERHASIL DIHAPUS" << endl;

        } else if (input == "7") {      // show data organisasi
            show_all_organisasi(LO);

        } else if (input == "8") {      // show data anggota
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : ";
            cin >> id_organisasi;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                show_all_anggota(p);
            }

        } else if (input == "9") {      // hitung jumlah organisasi
            n = count_organisasi(LO);
            cout << "Jumlah Organisasi adalah " << n << endl;

        } else if (input == "10") {     // hitung jumlah anggota
            if (count_organisasi(LO) == 0) {
                cout << "!!! DATA ORGANISASI MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan ID Organisasi : "; cin >> id_organisasi;
            cout << endl;

            p = search_organisasi(LO, id_organisasi);
            n = count_anggota(p);

            if (p == NULL) {
                cout << "!!! ORGANISASI TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "Jumlah Anggota dari Organisasi " << p->info.nama << " adalah " << n << endl;
            }

        } else if (input == "0") {     // exit
            break;

        } else {
            // TODO
            cout << WRONG_INPUT_PROMPT << endl;
        }

        wait_for_enter();
    }
}

void menu_mahasiswa(list_organisasi &LO, list_mahasiswa &LM) {
    string input, nim, id_prestasi;
    info_mahasiswa info;
    info_prestasi info_pres;
    adr_mahasiswa p;
    adr_prestasi q;
    adr_organisasi p_org;
    int n;

    while (true) {
        clear_screen();
        print_prompt_menu_mahasiswa();
        cout << "Pilih: "; cin >> input;
        cout << endl;

        if (input == "1") {             // insert data mahasisiwa
            cout << "Masukkan Data Mahasiswa" << endl;
            cout << "NIM        : " ; cin >> info.nim;
            cout << "Nama       : " ; cin >> info.nama;
            cout << "Jurusan    : " ; cin >> info.jurusan;
            cout << "Gender     : " ; cin >> info.gender;
            cout << "Angkatan   : " ; cin >> info.angkatan;

            if (search_mahasiswa(LM, info.nim) != NULL) {
                cout << "!!! MAHASISWA SUDAH TERDATA !!!" << endl;
            } else {
                insert_last_mahasiswa(LM, create_elm_mahasiswa(info));
                cout << "=== MAHASISWA BERHASIL DITAMBAHKAN ===" << endl;
            }

        } else if (input == "2") {      // insert data prestasi
            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan NIM Mahasiswa : "; cin >> nim;
            cout << endl;

            p = search_mahasiswa(LM, nim);

            cout << "Masukkan Data Prestasi" << endl;
            cout << "ID Prestasi    : "; cin >> info_pres.id;
            cout << "Nama           : "; cin >> info_pres.nama;
            cout << "Bidang         : "; cin >> info_pres.bidang;
            cout << "Urutan         : "; cin >> info_pres.urutan;
            cout << endl;

            if (search_prestasi(p, id_prestasi) != NULL) {
                cout << "!!! PRESTASI SUDAH TERDATA !!!" << endl;
            } else {
                insert_prestasi(p, create_elm_prestasi(info_pres));
                cout << "=== PRESTASI BERHASIL DITAMBAHKAN ===" << endl;
            }

        } else if (input == "3") {      // search data mahasiswa
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> nim;

            p = search_mahasiswa(LM, nim);

            if (p == NULL) {
                cout << "!!! MAHASISWA TIDAK DITEMUKAN !!!" << endl;
            } else {
                cout << "========   DATA MAHASISWA    ========" << endl;
                show_mahasiswa(p);
                cout << "======================================" << endl;
            }

        } else if (input == "4") {      // search data prestasi
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> nim;
            cout << "Masukkan ID Prestasi : ";
            cin >> id_prestasi;
            cout << endl;

            p = search_mahasiswa(LM, nim);

            if (p == NULL) {
                cout << "!!! MAHASISWA TIDAK DITEMUKAN !!!" << endl;
            } else {
                q = search_prestasi(p, id_prestasi);

                if (q == NULL) {
                    cout << "!!! PRESTASI TIDAK DITEMUKAN !!!" << endl;
                } else {
                    cout << "========    DATA PRESTASI     ========" << endl;
                    show_prestasi(q);
                    cout << "=====================================" << endl;
                }
            }

        } else if (input == "5") {      // delete data mahasiswa
            cout << "Masukkan NIM Mahasiswa : "; cin >> nim;
            cout << endl;

            p = delete_mahasiswa(LM, nim);

            if (p == NULL) {
                cout << "!!! DATA MAHASISWA TIDAK DITEMUKAN !!!" << endl;
            } else {
                p_org = LO.first;

                while (p_org != NULL) {
                    delete_anggota(p_org, nim);
                    p_org = p_org->next;
                }

                cout << "DATA MAHASISWA BERHASIL DIHAPUS" << endl;
            }

        } else if (input == "6") {      // delete data prestasi
            cout << "Masukkan NIM Mahasiswa : "; cin >> nim;
            cout << "Masukkan ID Prestasi   : "; cin >> id_prestasi;
            cout << endl;

            p = search_mahasiswa(LM, nim);
            q = delete_prestasi(p, id_prestasi);

            if (p == NULL) {
                cout << "!!! DATA MAHASISWA TIDAK DITEMUKAN !!!" << endl;
                cout << endl;
            } else if (q == NULL) {
                cout << "!!! DATA PRESTASI TIDAK DITEMUKAN !!!" << endl;
                cout << endl;
            } else {
                cout << "DATA PRESTASI BERHASIL DIHAPUS" << endl;
                cout << endl;
            }

        } else if (input == "7") {      // show data mahasiswa
            show_all_mahasiswa(LM);

        } else if (input == "8") {      // show data prestasi
            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan NIM Mahasiswa : "; cin >> nim;
            cout << endl;

            p = search_mahasiswa(LM, nim);

            if (p == NULL) {
                cout << "!!! DATA MAHASISWA TIDAK DITEMUKAN !!!" << endl;
            } else if (count_prestasi(p) == 0) {
                cout << "!!! DATA PRESTASI MASIH KOSONG !!!" << endl;
            } else {
                show_all_prestasi(p);
            }

        } else if (input == "9") {      // hitung jumlah mahasisiwa
            n = count_mahasiswa(LM);
            cout << "Jumlah Mahasiswa adalah " << n << endl;

        } else if (input == "10") {     // hitung jumlah prestasi
            if (count_mahasiswa(LM) == 0) {
                cout << "!!! DATA MAHASISWA MASIH KOSONG !!!" << endl;
                wait_for_enter();
                continue;
            }

            cout << "Masukkan NIM Mahasiswa : "; cin >> nim;
            cout << endl;

            p = search_mahasiswa(LM, nim);
            n = count_prestasi(p);

            cout << "Jumlah Prestasi " << p->info.nama << " adalah " << n << endl;

        } else if (input == "0") {     // exit
            break;
        } else {
            cout << WRONG_INPUT_PROMPT << endl;
        }

        wait_for_enter();
    }
}

void print_prompt_main_menu() {
    cout << "=============  MAIN MENU   =============" << endl;
    cout << "PILIH LIST: " << endl;
    cout << "1. ORGANISASI" << endl;
    cout << "2. MAHASISWA" << endl;
    cout << "3. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_organisasi() {
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
    cout << "0. EXIT" << endl;
    cout << "========================================" << endl;
}

void print_prompt_menu_mahasiswa() {
    cout << "=============  MAHASISWA   =============" << endl;
    cout << "1. INSERT DATA MAHASISWA" << endl;
    cout << "2. INSERT DATA PRESTASI" << endl;
    cout << "3. SEARCH DATA MAHASISWA" << endl;
    cout << "4. SEARCH DATA PRESTASI" << endl;
    cout << "5. DELETE DATA MAHASISWA" << endl;
    cout << "6. DELETE DATA PRESTASI" << endl;
    cout << "7. SHOW DATA MAHASISWA" << endl;
    cout << "8. SHOW DATA PRESTASI" << endl;
    cout << "9. HITUNG JUMLAH MAHASISWA" << endl;
    cout << "10. HITUNG JUMLAH PERAIH PRESTASI" << endl;
    cout << "0. EXIT" << endl;
    cout << "========================================" << endl;
}
