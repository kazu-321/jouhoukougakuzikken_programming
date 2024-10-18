#include "main.h"

// void swap_country_data(country_data_type* x, country_data_type* y) {
//     country_data_type temp;
//     temp = *x;
//     *x = *y;
//     *y = temp;
// }

// // パーティション関数
// int partition(int low, int high, int mode) {
//     int pivot = (mode == 0) ? strcmp(data[high].country, data[low].country) 
//                 : (mode == 1) ? data[high].gold
//                 : (mode == 2) ? data[high].silver
//                 : data[high].bronze;

//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         int compare = 0;
//         if (mode == 0) {
//             // 国名順 (A~Z)
//             if (strcmp(data[j].country, data[high].country) < 0) compare = 1;
//         } else if (mode == 1) {
//             // 金メダル数で比較
//             if (data[j].gold > data[high].gold) compare = 1;
//         } else if (mode == 2) {
//             // 銀メダル数で比較
//             if (data[j].silver > data[high].silver) compare = 1;
//         } else if (mode == 3) {
//             // 銅メダル数で比較
//             if (data[j].bronze > data[high].bronze) compare = 1;
//         }

//         if (compare) {
//             i++;
//             swap_country_data(&data[i], &data[j]);
//         }
//     }

//     swap_country_data(&data[i + 1], &data[high]);

//     return i + 1;
// }

// // クイックソートの再帰関数
// void quicksort(int low, int high, int mode) {
//     if (low < high) {
//         int pi = partition(low, high, mode);

//         // ピボットの左右に対して再帰的にクイックソートを実行
//         quicksort(low, pi - 1, mode);
//         quicksort(pi + 1, high, mode);
//     }
// }

// // ソート関数（クイックソート）
// void sort(int mode) {
//     quicksort(0, data_size - 1, mode);
// }


// 安定な比較関数
int compare_by_mode(const country_data_type* a, const country_data_type* b, int mode) {
    if (mode == 0) {
        return strcmp(a->country, b->country);   // 国名で昇順
    } else if (mode == 1) {
        return b->gold - a->gold;   // 金メダル数で降順
    } else if (mode == 2) {
        return b->silver - a->silver;   // 銀メダル数で降順
    } else if (mode == 3) {
        return b->bronze - a->bronze;   // 銅メダル数で降順
    } else if (mode == 4) {
        return b->sum - a->sum;   // 合計メダル数で降順
    }
    return 0;  // デフォルトは等しいと見なす
}

// 安定なマージ関数
void merge(country_data_type arr[], int left, int mid, int right, int mode) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    country_data_type L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compare_by_mode(&L[i], &R[j], mode) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// マージソート関数
void mergeSort(country_data_type arr[], int left, int right, int mode) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, mode);
        mergeSort(arr, mid + 1, right, mode);

        merge(arr, left, mid, right, mode);
    }
}

// ソート関数
void sort(int mode) {
    mergeSort(data, 0, data_size - 1, mode);
}
