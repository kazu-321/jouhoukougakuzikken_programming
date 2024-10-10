#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

extern char country[30][100];
extern int gold[100];
extern int silver[100];
extern int bronze[100];
extern int medal_rank[100];
extern int data_size;

void sort(int mode);
void input();

#endif