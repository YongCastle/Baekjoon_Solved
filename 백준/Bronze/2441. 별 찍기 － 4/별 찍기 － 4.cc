#include <iostream>
#include <cstdio>

int main(void){
    int N; scanf("%d", &N);

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            printf(" ");
        }
        for(int j=N-i; j>0; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}