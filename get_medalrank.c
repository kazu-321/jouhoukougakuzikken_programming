#include "main.h"

int get_medalrank(int index){
    sort(3);
    sort(2);
    sort(1);
    int i;
    for(i=0;i<data_size;i++){
        data[i].medal_rank=i+1;
    }
    return data[index].medal_rank;
}