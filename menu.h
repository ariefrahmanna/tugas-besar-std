#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>
#include "adt.h"
#include "utilities.h"

void menu_organisasi(list_organisasi &LO, list_mahasiswa &LM);
void menu_mahasiswa(list_organisasi &LO, list_mahasiswa &LM);
void print_prompt_main_menu();
void print_prompt_menu_organisasi();
void print_prompt_menu_mahasiswa();

#endif // MENU_H_INCLUDED
