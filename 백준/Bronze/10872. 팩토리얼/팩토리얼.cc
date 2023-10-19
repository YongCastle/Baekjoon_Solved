#include <cstdio>

int main(void){
    int N;
    
    scanf("%d", &N);
    int sum=1;
    for(int i=2; i<=N; i++){
        sum*=i;
    }
    printf("%d", sum);
}