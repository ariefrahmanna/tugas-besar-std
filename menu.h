#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "adt.h"
#include "utilities.h"

void menu_organisasi(list_organisasi &LP, list_mahasiswa &LC);
void menu_mahasiswa(list_mahasiswa &LP);
void print_prompt_main_menu();
void print_prompt_menu_organisasi();
void print_prompt_menu_mahasiswa();

#endif // MENU_H_INCLUDED
