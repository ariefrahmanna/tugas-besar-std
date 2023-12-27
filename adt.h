#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elm_organisasi *adr_organisasi;
typedef struct elm_mahasiswa *adr_mahasiswa;
typedef struct elm_prestasi *adr_prestasi;
typedef struct elm_anggota *adr_anggota;

struct info_organisasi {
    string id;
    string nama;
    string bidang;
    int sejak_tahun;
};

struct info_mahasiswa {
    string nim;
    string nama;
    string jurusan;
    string gender;
    int angkatan;
};

struct info_prestasi {
    string id;
    string nama;
    string bidang;
    int urutan;
};

struct elm_organisasi {
    info_organisasi info;
    adr_organisasi next;
    adr_anggota anggota;
};

struct elm_mahasiswa {
    info_mahasiswa info;
    adr_mahasiswa next;
    adr_prestasi prestasi;
};

struct elm_prestasi {
    info_prestasi info;
    adr_prestasi next;
};

struct elm_anggota {
    adr_anggota next;
    adr_mahasiswa value;
    string nim;
};


struct list_organisasi {
    adr_organisasi first;
};

struct list_mahasiswa {
    adr_mahasiswa first;
};


// create list
void create_list_organisasi(list_organisasi &L);
void create_list_mahasiswa(list_mahasiswa &L);
// create element
adr_organisasi create_elm_organisasi(info_organisasi x);
adr_mahasiswa create_elm_mahasiswa(info_mahasiswa x);
adr_prestasi create_elm_prestasi(info_prestasi x);
// insert
void insert_first_organisasi(list_organisasi &L, adr_organisasi p);
void insert_first_mahasiswa(list_mahasiswa &L, adr_mahasiswa p);
void insert_last_organisasi(list_organisasi &L, adr_organisasi p);
void insert_last_mahasiswa(list_mahasiswa &L, adr_mahasiswa p);
// delete
adr_organisasi delete_organisasi(list_organisasi &L, string id_organisasi);
adr_mahasiswa delete_mahasiswa(list_mahasiswa &L, string nim);
// searching on list
adr_organisasi search_organisasi(list_organisasi L, string id_organisasi);
adr_mahasiswa search_mahasiswa(list_mahasiswa L, string nim);
// edit
void edit_organisasi(adr_organisasi p, string new_nama, string new_bidang, int new_sejak_tahun);
void edit_mahasiswa(adr_mahasiswa p, string new_nama, string new_jurusan);
void edit_prestasi(adr_prestasi p, string new_nama, string new_bidang, int new_urutan);
// count on list
int count_organisasi(list_organisasi L);
int count_mahasiswa(list_mahasiswa L);
// show all
void show_all_organisasi(list_organisasi L);
void show_all_mahasiswa(list_mahasiswa L);
// show info
void show_organisasi(adr_organisasi p);
void show_mahasiswa(adr_mahasiswa p);

// search on relation
adr_anggota search_anggota(adr_organisasi p, string nim);
adr_prestasi search_prestasi(adr_mahasiswa p, string id_prestasi);
// insert relation
void insert_anggota(list_mahasiswa L, adr_organisasi p, string nim);
void insert_prestasi(adr_mahasiswa p, adr_prestasi q);
// delete relation
adr_anggota delete_anggota(adr_organisasi p, string nim);
adr_prestasi delete_prestasi(adr_mahasiswa p, string id_prestasi);
// count relation
int count_anggota(adr_organisasi p);
int count_prestasi(adr_mahasiswa p);
// show all
void show_all_anggota(adr_organisasi p);
void show_all_prestasi(adr_mahasiswa p);
// show info
void show_prestasi(adr_prestasi p);

#endif // ADT_H_INCLUDED
