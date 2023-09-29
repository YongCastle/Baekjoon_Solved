#include <cstdio>


int main(void){
    int A;
    scanf("%d", &A);

    //Height
    for(int i=0; i<A; i++){
        //Star
        for(int j=1; j<A-i; j++){
            printf(" ");
        }
        for(int j=0; j<i+1; j++){
            printf("*");
        }
        printf("\n");
    }
}