#include "main.h"

void load(char* filename){
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("ファイルが開けません\n");
        return;
    }
    char buf[4][100];
    fscanf(fp, "%s, %s, %s, %s", buf[0], buf[1], buf[2], buf[3]);
    data_size = 0;
    while(fscanf(fp, "%s %d %d %d", data[data_size].country, &data[data_size].gold, &data[data_size].silver, &data[data_size].bronze) != EOF){
        data[data_size].medal_rank = get_medalrank(data_size);
        data_size++;
    }
    fclose(fp);
}