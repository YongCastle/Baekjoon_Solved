#include <cstdio>

int main(void){
    int N;
    scanf("%d", &N);
    int i=1;
    while(N!=1){
        i++;
        while(N%i==0){
            printf("%d\n", i);
            N/=i;
        }
    }
    return 0;
}