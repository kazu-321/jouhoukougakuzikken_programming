#include "main.h"

void get_sum(){
    for(int i=0;i<data_size;i++){
        data[i].sum=data[i].gold+data[i].silver+data[i].bronze;
    }
}