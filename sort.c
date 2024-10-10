// int配列の値をスワップするための関数
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// char*配列の値をスワップするための関数
void swap_str(char* str1, char* str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// パーティション関数
int partition(int low, int high, int mode) {
    int pivot = (mode == 0) ? strcmp(country[high], country[low]) 
                : (mode == 1) ? gold[high]
                : (mode == 2) ? silver[high]
                : bronze[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        int compare = 0;
        if (mode == 0) {
            // 国名順 (A~Z)
            if (strcmp(country[j], country[high]) < 0) compare = 1;
        } else if (mode == 1) {
            // 金メダル数で比較
            if (gold[j] > gold[high]) compare = 1;
        } else if (mode == 2) {
            // 銀メダル数で比較
            if (silver[j] > silver[high]) compare = 1;
        } else if (mode == 3) {
            // 銅メダル数で比較
            if (bronze[j] > bronze[high]) compare = 1;
        }

        if (compare) {
            i++;
            swap_str(country[i], country[j]); // 国名をスワップ
            swap(&gold[i], &gold[j]);         // 金メダル数をスワップ
            swap(&silver[i], &silver[j]);     // 銀メダル数をスワップ
            swap(&bronze[i], &bronze[j]);     // 銅メダル数をスワップ
        }
    }

    swap_str(country[i + 1], country[high]);
    swap(&gold[i + 1], &gold[high]);
    swap(&silver[i + 1], &silver[high]);
    swap(&bronze[i + 1], &bronze[high]);

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
