#ifndef UTIL_H
#define UTIL_H

#include "types.h"

void memory_copy(char *source, char *dest, int nbytes);
void memory_set(uint8 *dest, uint8 val, uint32 len);
void int_to_ascii(int n, char str[]);

/* NOVAS funções */
extern string int_to_string(int n);
int str_to_int(string ch);
void *malloc(int nbytes);

#endif

