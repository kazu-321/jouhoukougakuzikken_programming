#include "main.h"

void load(char* filename){
    FILE *fp;
    char full_filename[256];
    snprintf(full_filename, sizeof(full_filename), "%s.csv", filename);
    fp = fopen(full_filename, "r");
    if(fp == NULL){
        printf("ファイルが開けません\n");
        return;
    }
    printd("load data start\n");
    char buf[4][100];
    fscanf(fp, "%[^,],%[^,],%[^,],%s\n", buf[0], buf[1], buf[2], buf[3]);
    printd("header: %s, %s, %s, %s\n", buf[0], buf[1], buf[2], buf[3]);
    data_size = 0;
    while(fscanf(fp, "%[^,],%d,%d,%d\n", data[data_size].country, &data[data_size].gold, &data[data_size].silver, &data[data_size].bronze) != EOF){
        data[data_size].medal_rank = get_medalrank(data_size);
        printd("load data[%d]: %s %d %d %d %d\n", data_size, data[data_size].country, data[data_size].gold, data[data_size].silver, data[data_size].bronze, data[data_size].medal_rank);
        data_size++;
    }
    fclose(fp);
}