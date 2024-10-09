#include <stdio.h>
#include <string.h>


char country[30][100];
int gold[100];
int silver[100];
int bronze[100];

int search() {
    char x[30];

    printf("Enter Country Name >>>"); scanf("%s",&x);
    
    for(int i=0;i<=100;i++){
        strcmp(x[0],country[0][i]);
        if(strcmp(x[0],country[0][i])==0){
            printf("国名：%s\n
                    金：%d個\n
                    銀：個\n
                    銅%d\n
                    \n
                    メダル順位%d位\n",x,gold[i],silver[i],brinze[i],)
        }
    }
    if (strcmp(x[30],country[]))

}