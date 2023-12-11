#include "adt.h"

void create_list_organisasi(list_organisasi &L) {
    L.first = NULL;
}

void create_list_mahasiswa(list_mahasiswa &L) {
    L.first = NULL;
}

void create_list_prestasi(list_prestasi &L) {
    L.first = NULL;
}

adr_organisasi create_elm_organisasi(info_organisasi x) {
    adr_organisasi p = new elm_organisasi();

    p->info = x;
    p->next = NULL;
    p->anggota = NULL;

    return p;
}

adr_mahasiswa create_elm_mahasiswa(info_mahasiswa x) {
    adr_mahasiswa p = new elm_mahasiswa();

    p->info = x;
    p->next = NULL;
    p->peraih = NULL;

    return p;
}

adr_prestasi create_elm_prestasi(info_prestasi x) {
    adr_prestasi p = new elm_prestasi();

    p->info = x;
    p->next = NULL;

    return p;
}

void insert_first_organisasi(list_organisasi &L, adr_organisasi p) {
    if (L.first != NULL) {
        p->next = L.first;
    }

    L.first = p;
}

void insert_first_mahasiswa(list_mahasiswa &L, adr_mahasiswa p) {
    if (L.first != NULL) {
        p->next = L.first;
    }

    L.first = p;
}

void insert_first_prestasi(list_prestasi &L, adr_prestasi p) {
    if (L.first != NULL) {
        p->next = L.first;
    }

    L.first = p;
}

void insert_last_organisasi(list_organisasi &L, adr_organisasi p) {
    adr_organisasi last;

    if (L.first == NULL) {
        L.first = p;
    } else {
        last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = p;
    }
}

void insert_last_mahasiswa(list_mahasiswa &L, adr_mahasiswa p) {
    adr_mahasiswa last;

    if (L.first == NULL) {
        L.first = p;
    } else {
        last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = p;
    }
}

void insert_last_prestasi(list_prestasi &L, adr_prestasi p) {
    adr_prestasi last;

    if (L.first == NULL) {
        L.first = p;
    } else {
        last = L.first;
        while (last->next != NULL) last = last->next;
        last->next = p;
    }
}

adr_organisasi delete_organisasi(list_organisasi &L, string id_organisasi) {
    // TODO
    return NULL;
}

adr_mahasiswa delete_mahasiswa(list_mahasiswa &L, string nim) {
    // TODO
    return NULL;
}

adr_prestasi delete_prestasi(list_prestasi &L, string id_prestasi) {
    // TODO
    return NULL;
}

adr_organisasi search_organisasi(list_organisasi L, string id_organisasi) {
    adr_organisasi p = L.first;

    while (p != NULL) {
        if (p->info.id == id_organisasi) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

adr_mahasiswa search_mahasiswa(list_mahasiswa L, string nim) {
    adr_mahasiswa p = L.first;

    while (p != NULL) {
        if (p->info.nim == nim) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

adr_prestasi search_prestasi(list_prestasi L, string id_prestasi) {
    adr_prestasi p = L.first;

    while (p != NULL) {
        if (p->info.id == id_prestasi) {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

void edit_organisasi(adr_organisasi p, string new_nama, string new_bidang, int new_sejak_tahun) {
    p->info.nama = new_nama;
    p->info.bidang = new_bidang;
    p->info.sejak_tahun = new_sejak_tahun;
}

void edit_mahasiswa(adr_mahasiswa p, string new_nama, string new_jurusan) {
    p->info.nama = new_nama;
    p->info.jurusan = new_jurusan;
}

void edit_prestasi(adr_prestasi p, string new_nama, string new_bidang, int new_urutan) {
    p->info.nama = new_nama;
    p->info.bidang = new_bidang;
    p->info.urutan = new_urutan;
}

int count_organisasi(list_organisasi L) {
    int n = 0;
    adr_organisasi p = L.first;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

int count_mahasiswa(list_mahasiswa L) {
    int n = 0;
    adr_mahasiswa p = L.first;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

int count_prestasi(list_prestasi L) {
    int n = 0;
    adr_prestasi p = L.first;

    while (p != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

void show_all_organisasi(list_organisasi L) {
    // TODO
}

void show_all_mahasiswa(list_mahasiswa L) {
    // TODO
}

void show_all_prestasi(list_prestasi L) {
    // TODO
}

adr_anggota search_anggota(adr_organisasi p, string nim) {
    adr_anggota q = p->anggota;

    while (q != NULL) {
        if (q->nim == nim) {
            return q;
        }

        q = q->next;
    }

    return NULL;
}

adr_peraih search_peraih(adr_mahasiswa p, string id_prestasi) {
    adr_peraih q = p->peraih;

    while (q != NULL) {
        if (q->id_prestasi == id_prestasi) {
            return q;
        }

        q = q->next;
    }

    return NULL;
}

void insert_anggota(adr_organisasi p, string nim) {
    // TODO
}

void insert_peraih(adr_mahasiswa p, string id_prestasi) {
    // TODO
}

void delete_anggota(adr_organisasi p, string nim) {
    // TODO
}

void delete_peraih(adr_mahasiswa p, string id_prestasi) {
    // TODO
}

int count_anggota(adr_organisasi p) {
    int n = 0;
    adr_anggota q = p->anggota;

    while (q != NULL) {
        q = q->next;
        n++;
    }

    return n;
}

int count_peraih(adr_mahasiswa p) {
    int n = 0;
    adr_peraih q = p->peraih;

    while (q != NULL) {
        q = q->next;
        n++;
    }

    return n;
}

void show_mahasiswa(adr_organisasi p) {
    // TODO
}

void show_prestasi(adr_mahasiswa p) {
    // TODO
}
