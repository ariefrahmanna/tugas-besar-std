#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void menu_organisasi(list_organisasi &LP, list_mahasiswa &LC);
void menu_mahasiswa(list_mahasiswa &LP, list_prestasi &LC);
void menu_prestasi(list_prestasi &L);
void print_prompt_main_menu();
void print_prompt_menu_organisasi();
void print_prompt_menu_mahasiswa();
void print_prompt_menu_prestasi();

#endif // MENU_H_INCLUDED
