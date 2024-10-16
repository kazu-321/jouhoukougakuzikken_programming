#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>  // 可変引数を処理するために必要

typedef struct COUNTRY_DATA{
    char country[100];
    int gold;
    int silver;
    int bronze;
    int medal_rank;
} country_data_type;

extern country_data_type data[1000];  // データ構造体
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
void search();                  // データ検索関数
int get_medalrank(int index);   // メダルランク順位を取得する関数
void show();                    // データ表示関数
void show_medalrank();          // メダルランク表示関数
#endif