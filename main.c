#include "main.h"

char country[30][100];
int gold[100];
int silver[100];
int bronze[100];
int medal_rank[100];
int data_size=0;
int debug_mode=0;

int main(int argc, char* argv[]){
    printf("\033[2J\033[0;0H");
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
            printf("+----------------+---------------------------+\n");
            printf("| コマンド       | 説明                      |\n");
            printf("+----------------+---------------------------+\n");
            printf("| help           | ヘルプを表示します        |\n");
            printf("| input          | データを追加します        |\n");
            printf("| sort           | データをソートします      |\n");
            printf("| show           | データ一覧を表示します    |\n");
            printf("| show_medalrank | メダルランク順に表示します|\n");
            printf("| search         | データを検索します        |\n");
            printf("| exit           | プログラムを終了します    |\n");
            printf("| load           | データを読み込みます      |\n");
            printf("| save           | データを保存します        |\n");
            printf("+----------------+---------------------------+\n");
        }else if(strcmp(command,"input")==0){
            printd("input data start\n");
            input();
            printd("input data end\n");
            for(int i=0;i<5;i++) printf("\033[A\033[K");
            printf("追加[%d]: 国名:%s 金:%d 銀:%d 銅:%d, メダルランク:%d\n",data_size,country[data_size-1],gold[data_size-1],silver[data_size-1],bronze[data_size-1],get_medalrank(data_size-1));
        }else if(strcmp(command,"sort")==0){
            printd("sort data\n");
            printf("ソートモードを入力してください 0:国順, 1:金, 2:銀, 3:銅\n>>> ");
            int mode;
            scanf("%d",&mode);
            sort(mode);
            printf("\033[A\033[K\033[A\033[K");            
            printf("ソート完了 (モード: %d)\n",mode);
        }else if(strcmp(command,"show")==0){
            show();
        }else if(strcmp(command,"show_medalrank")==0){
            show_medalrank();
        }else if(strcmp(command,"search")==0){
            search();
        }else if(strcmp(command,"exit")==0){
            printd("プログラムを終了します\n");
            break;
        }else{
            printf("%sというコマンドはありません\n",command);
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

void show(){
    printd("show data\n");
    printf("+----------------------------------------------+\n");
    printf("|      国名       |  金  |  銀  |  銅  |ﾒﾀﾞﾙﾗﾝｸ|\n");
    printf("+-----------------+------+------+------+-------+\n");
    for(int i=0;i<data_size;i++){
        printf("| %15s |  %02d  |  %02d  |  %02d  |  \n",country[i],gold[i],silver[i],bronze[i]);
    }
    printf("+--------------------------------------+\n");
}