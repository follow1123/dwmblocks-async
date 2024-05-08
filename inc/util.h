#pragma once

#define LEN(arr)  (sizeof(arr) / sizeof(arr[0]))
#define MAX(a, b) (a > b ? a : b)

#include <stddef.h>

int gcd(int, int);
void closePipe(int[2]);
void trimUTF8(char*, unsigned int);
void initdatahome();
char *concat_datahome(const char*);
