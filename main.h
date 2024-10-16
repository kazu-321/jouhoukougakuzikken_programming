#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>  // 可変引数を処理するために必要

extern char country[30][100];   // 国名
extern int  gold[100];           // 金メダル
extern int  silver[100];         // 銀メダル
extern int  bronze[100];         // 銅メダル
extern int  medal_rank[100];     // メダルランク順位情報
extern int data_size;           // 現在のデータ数

extern int debug_mode;
/*
ソート関数
mode: 0:国名, 1:金メダル数, 2:銀メダル数, 3:銅メダル数
*/
void sort(int mode);
void input();                   // データ入力関数
void printd(const char *format, ...);   // デバッグ用出力関数
void load(char* filename);      // ファイルからデータを読み込む関数
void save(char* filename);      // ファイルにデータを保存する関数
int get_medalrank(int index);   // メダルランク順位を取得する関数
void show();                    // データ表示関数
void show_medalrank();          // メダルランク表示関数
#endif