#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <iostream>
#include <limits>
using namespace std;

const string WRONG_INPUT_PROMPT = "Pilihan anda salah, silahkan input lagi.";
const string WAIT_FOR_ENTER_PROMPT = "\nTekan Enter untuk lanjut...";

void validate_repeat(string &input, string prompt);
void clear_screen();
void wait_for_enter();

#endif // UTILITIES_H_INCLUDED
