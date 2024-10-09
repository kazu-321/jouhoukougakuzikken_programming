#include <stdio.h>
void load();

int main(void){
    load();
    
}

void load(){
    FILE *fp;
    char *fname = "load.cvs";
    char country[30][100];
    int gold[100], silver[100], bronze[100], total[100];
    char garbage[100][100];

    int i = 0;
    int num = 0;
    char c;
    

    printf("---input---");
    do{
        printf("\n[NO.%d]\n\n",num+1);

        gets(garbage[num]);
        printf("国名："); gets(country[num]); trim(country[num]);
        printf("金："); scanf("%d", &gold[num]);
        printf("銀："); scanf("%d", &silver[num]);
        printf("銅："); scanf("%d", &bronze[num]);
        printf("合計："); scanf("%d", &total[num]);
        printf("%s, %d, %d, %d, %d",country,gold,silver,bronze,total);

        num++;
        printf("\n 続けて入力しますか？(y/n)");
        scanf("%*c%c", &c);
    }while (c == 'y '|| c == 'Y');

    fp=fopen(fname, "w");
    if (fp == NULL){
        printf("ファイルが開けません\n");
        return -1;
    }
    for (i = 0; i < num; i++){
        fprintf(fp, "%s, %d, %d, %d, %d\n", country[i], gold[i], silver[i], bronze[i], total[i])
    }

    fclose(fp);
    printf("---output---\n");
    return 0;



}