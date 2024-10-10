#include "main.h"

char country[30][100];
int gold[100];
int silver[100];
int bronze[100];
int medal_rank[100];
int data_size=0;
int debug_mode=0;

int main(int argc, char* argv[]){
    printf("Welcome to medal ranking system\n");
    printf("type help to show help\n");
    if(argc>1 && strcmp(argv[1],"debug")==0){
        debug_mode=1;
        printd("debug mode\n");
    }
    while(1){
        printf("$ ");
        char command[100];
        scanf("%s",command);
        printd("input command: %s\n",command);
        if(strcmp(command,"help")==0){
            printd("show help\n");
            printf("-------------------------\n");
            printf("| help  : show help\n");
            printf("| input : input data\n");
            printf("| sort  : sort data\n");
            printf("| show  : show data\n");
            printf("| exit  : exit program\n");
            printf("-------------------------\n");
        }else if(strcmp(command,"input")==0){
            printd("input data\n");
            input();
        }else if(strcmp(command,"sort")==0){
            printd("sort data\n");
            printf("enter sort mode: 0:country, 1:gold, 2:silver, 3:bronze\n>>> ");
            int mode;
            scanf("%d",&mode);
            sort(mode);
        }else if(strcmp(command,"show")==0){
            printd("show data\n");
            printf("+--------------------------------------+\n");
            printf("|      country    | gold |silver|bronze|\n");
            printf("+-----------------+------+------+------+\n");
            for(int i=0;i<data_size;i++){
                printf("| %15s |  %02d  |  %02d  |  %02d  |\n",country[i],gold[i],silver[i],bronze[i]);
            }
            printf("+--------------------------------------+\n");
        }else if(strcmp(command,"exit")==0){
            printd("exit program\n");
            break;
        }else{
            printf("invalid command: %s\n",command);
        }
    }
    return 0;
}


void printd(const char *format, ...) {
    if(debug_mode){
        // 可変引数を処理するための準備
        va_list args;
        va_start(args, format);

        // デバッグメッセージの前に追加する文字列
        printf("\033[2m[DEBUG] ");

        // vprintfを使用して可変引数に対応する形でフォーマットされた出力を行う
        vprintf(format, args);

        // デバッグメッセージの終わりに追加する文字列
        printf("\033[0m");

        // 可変引数の処理を終了
        va_end(args);
    }
}