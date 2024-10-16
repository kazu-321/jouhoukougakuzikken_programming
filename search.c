#include "main.h"

int search() {
    char name[30];

    printf("国名を入力 >>>"); scanf("%s",name);
    
    for(int i=0;i<=data_size;i++){
        if(strcmp(name[0],country[0][i])==0){
            printf("国名：%s\n",name);
            printf("メダル順位：%d位",medal_rank[i]);
            printf("金：%d個\n",gold[i]);
            printf("銀：%d個\n",silver[i]);
            printf("銅：%d個\n",bronze[i]);
        }
    }
    
    return 0;

}