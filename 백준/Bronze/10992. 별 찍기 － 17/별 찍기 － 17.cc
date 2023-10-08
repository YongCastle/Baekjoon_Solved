#include <iostream>
#include <cstdio>

int main(void){
    int N; scanf("%d", &N);
    char ch;

    if(N!=1){
        for(int j=0; j<N-1; j++)
            printf(" ");
        printf("*");
        printf("\n");
    }
    for(int i=1; i<N-1; i++){
        for(int j=0; j<N-1-i; j++){
            printf(" ");
        }
        printf("*");
        for(int j=0; j<2*i-1; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for(int j=0; j<2*N-1; j++)
        printf("*");
    return 0;
}