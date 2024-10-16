#include "main.h"

void search(){
    char* name;

    printf("国名を入力 >>>"); scanf("%s",name);
    
    for(int i=0;i<=data_size;i++){
        if(strcmp(name,country[i])==0){
            printf("国名：%s\n",country[i]);
            printf("メダル順位：%d位",medal_rank[i]);
            printf("金：%d個\n",gold[i]);
            printf("銀：%d個\n",silver[i]);
            printf("銅：%d個\n",bronze[i]);

            break;
        }
    }
}