#include <stdio.h>
#include <string.h>


char country[30][100];
int gold[100], silver[100], bronze[100], total[100];
char garbage[100][100];


// 配列をスワップするためのヘルパー関数
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_str(char* str1, char* str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// ソート関数（クイックソートの仕組みを使用）
void sort(int mode) {
    int n = sizeof(gold) / sizeof(gold[0]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int swap_needed = 0;

            if (mode == 0) {
                // 国名順(A~Z)にソート
                if (strcmp(country[i], country[j]) > 0) {
                    swap_needed = 1;
                }
            } else if (mode == 1) {
                // 金メダル数(gold)が多い順にソート
                if (gold[i] < gold[j]) {
                    swap_needed = 1;
                }
            } else if (mode == 2) {
                // 銀メダル数(silver)が多い順にソート
                if (silver[i] < silver[j]) {
                    swap_needed = 1;
                }
            } else if (mode == 3) {
                // 銅メダル数(bronze)が多い順にソート
                if (bronze[i] < bronze[j]) {
                    swap_needed = 1;
                }
            }

            // 交換が必要な場合
            if (swap_needed) {
                swap_str(country[i], country[j]); // 国名をスワップ
                swap(&gold[i], &gold[j]);         // 金メダル数をスワップ
                swap(&silver[i], &silver[j]);     // 銀メダル数をスワップ
                swap(&bronze[i], &bronze[j]);     // 銅メダル数をスワップ
            }
        }
    }
}