#include <cstdio>

int main(void){
    int M, N;
    scanf("%d %d", &M, &N);
    
    long long N_5=0, M_5=0, MN_5=0;
    long long N_2=0, M_2=0, MN_2=0;
    long long div5 = 5;
    long long div2 = 2;
    while(M/div2){
        M_2 += M/div2;
        N_2 += N/div2;
        MN_2 += (M-N)/div2;
        div2*=2;
    }
    while(M/div5){
        M_5 += M/div5;
        N_5 += N/div5;
        MN_5 += (M-N)/div5;
        div5 *= 5;
    }
    long long sum_2 = M_2-N_2-MN_2;
    long long sum_5 = M_5-N_5-MN_5;
    printf("%lld", (sum_2>sum_5)? sum_5 : sum_2);
    return 0;
}