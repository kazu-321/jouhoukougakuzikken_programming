#include "main.h"

void input(){
    printf("[NO.%d]\n",data_size+1);
    printf("国名："); scanf("%s",data[data_size].country); 
    printf("金："); scanf("%d", &data[data_size].gold);
    printf("銀："); scanf("%d", &data[data_size].silver);
    printf("銅："); scanf("%d", &data[data_size].bronze);
    data_size++;
}