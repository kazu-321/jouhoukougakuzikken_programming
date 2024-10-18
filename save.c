#include "main.h"

void save(char* filename){
    FILE *fp;
    char full_filename[256];
    snprintf(full_filename, sizeof(full_filename), "./data/%s.csv", filename);
    fp = fopen(full_filename, "w");
    if(fp == NULL){
        printf("ファイルが開けません\n");
        return;
    }
    printd("save data start\n");
    fprintf(fp, "Country,Gold,Silver,Bronze\n");
    for(int i = 0; i < data_size; i++){
        fprintf(fp, "%s,%d,%d,%d\n", data[i].country, data[i].gold, data[i].silver, data[i].bronze);
        printd("save data[%d]: %s %d %d %d\n", i, data[i].country, data[i].gold, data[i].silver, data[i].bronze);
    }
    fclose(fp);
}