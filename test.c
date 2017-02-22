#include <stdio.h>

int main(void){
    int j = 1;
    for(int i  = 0; i < 1297; i ++){
        j = j* 3841;
        j = j% 5671;
    }
    printf("%d", j%5671);
}
