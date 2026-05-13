#ifndef SHELL_H
#define SHELL_H

#include "util.h"

// Protótipos das funções do shell
void launch_shell(int n);
void sum();
void fill_array(int arr[], int n);
void print_array(int arr[], int n);
extern int sum_array(int arr[], int n);
void echo();
void sort();
void insertion_sort(int arr[], int n, int order);
void fibonacci();
int fibo(int n);
void mmc();
int mdc(int x, int y, int flag);
void set_bg_color();
void help();

#endif

