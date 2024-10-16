#include "main.h"

void swap_country_data(country_data_type* x, country_data_type* y) {
    country_data_type temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// パーティション関数
int partition(int low, int high, int mode) {
    int pivot = (mode == 0) ? strcmp(data[high].country, data[low].country) 
                : (mode == 1) ? data[high].gold
                : (mode == 2) ? data[high].silver
                : data[high].bronze;

    int i = low - 1;

    for (int j = low; j < high; j++) {
        int compare = 0;
        if (mode == 0) {
            // 国名順 (A~Z)
            if (strcmp(data[j].country, data[high].country) < 0) compare = 1;
        } else if (mode == 1) {
            // 金メダル数で比較
            if (data[j].gold > data[high].gold) compare = 1;
        } else if (mode == 2) {
            // 銀メダル数で比較
            if (data[j].silver > data[high].silver) compare = 1;
        } else if (mode == 3) {
            // 銅メダル数で比較
            if (data[j].bronze > data[high].bronze) compare = 1;
        }

        if (compare) {
            i++;
            swap_country_data(&data[i], &data[j]);
        }
    }

    swap_country_data(&data[i + 1], &data[high]);

    return i + 1;
}

// クイックソートの再帰関数
void quicksort(int low, int high, int mode) {
    if (low < high) {
        int pi = partition(low, high, mode);

        // ピボットの左右に対して再帰的にクイックソートを実行
        quicksort(low, pi - 1, mode);
        quicksort(pi + 1, high, mode);
    }
}

// ソート関数（クイックソート）
void sort(int mode) {
    quicksort(0, data_size - 1, mode);
}
