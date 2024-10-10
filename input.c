#include "main.h"

void input(){
    printf("\n[NO.%d]\n\n",data_size+1);
    printf("国名："); scanf("%s",country[data_size]); 
    printf("金："); scanf("%d", &gold[data_size]);
    printf("銀："); scanf("%d", &silver[data_size]);
    printf("銅："); scanf("%d", &bronze[data_size]);
    printf("%s, %d, %d, %d \n",country[data_size],gold[data_size],silver[data_size],bronze[data_size]);
    data_size++;
}