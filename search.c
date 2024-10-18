#include "main.h"

void search(){
    char* name;

    printf("国名を入力 >>>"); scanf("%s",name);
    
    for(int i=0;i<=data_size;i++){
        if(strcmp(name,data[i].country)==0){
            printf("国名：%s\n",data[i].country);
            printf("メダル順位：%2d位",data[i].medal_rank);
            printf("金：%2d個\n",data[i].gold);
            printf("銀：%2d個\n",data[i].silver);
            printf("銅：%2d個\n",data[i].bronze);
            return;
        }
    }
}