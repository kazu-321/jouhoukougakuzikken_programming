#include <stdio.h>


void input(){
    
    int i = 0;
    int num = 0;
    char c;
    

    printf("---input---");
    do{
        printf("\n[NO.%d]\n\n",num+1);

        gets(garbage[num]);
        printf("国名："); gets(country[num]); 
        printf("金："); scanf("%d", &gold[num]);
        printf("銀："); scanf("%d", &silver[num]);
        printf("銅："); scanf("%d", &bronze[num]);
        printf("%s, %d, %d, %d ",country,gold,silver,bronze);

        num++;
        printf("\n 続けて入力しますか？(y/n)");
        scanf("%*c%c", &c);
    }while (c == 'y'|| c == 'Y');

  



}