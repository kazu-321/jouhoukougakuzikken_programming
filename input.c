#include "main.h"

void input(){
    printf("[NO.%d]\n",data_size+1);
    printf("国名："); scanf("%s",country[data_size]); 
    printf("金："); scanf("%d", &gold[data_size]);
    printf("銀："); scanf("%d", &silver[data_size]);
    printf("銅："); scanf("%d", &bronze[data_size]);
    data_size++;
}