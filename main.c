#include "main.h"

char country[30][100];
int gold[100];
int silver[100];
int bronze[100];
int medal_rank[100];
int data_size=0;

int main(void){
    printf("type help to show help\n");
    while(1){
        printf("$ ");
        char command[100];
        scanf("%s",command);
        if(strcmp(command,"help")==0){
            printf("-------------------------\n");
            printf("| help  : show help\n");
            printf("| input : input data\n");
            printf("| sort  : sort data\n");
            printf("| show  : show data\n");
            printf("| exit  : exit program\n");
            printf("-------------------------\n");
        }else if(strcmp(command,"input")==0){
            input();
        }else if(strcmp(command,"sort")==0){
            printf("enter sort mode: 0:country, 1:gold, 2:silver, 3:bronze\n>>> ");
            int mode;
            scanf("%d",&mode);
            sort(mode);
        }else if(strcmp(command,"show")==0){
            for(int i=0;i<data_size;i++){
                printf("%s, %d, %d, %d\n",country[i],gold[i],silver[i],bronze[i]);
            }
        }else if(strcmp(command,"exit")==0){
            break;
        }else{
            printf("invalid command\n");
        }

    }
    return 0;
}