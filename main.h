#ifndef MAIN_H
#define MAIN_H
#include <QString>
#include <string>

/* prototype of the functions in main.cpp files to be called in other files.
*/

int generate_random(int min, int max);

QString int_to_Qstring(int num);

void number_generator(int num, int* arry);

QString equation_generator(int* arry, int* ans);

#endif // MAIN_H
