#include <cstdio>


int main(void){
    int N, K; scanf("%d %d", &N, &K);
    int coins[N];    
    for(int i=0; i<N; i++){
        scanf("%d", &coins[i]);
    }
    
    int cnt = N;
    int ans = 0;
    while(cnt-- > 0 && K != 0){
        if(coins[cnt] <= K){
            ans += K / coins[cnt];
            K = K % coins[cnt];
        }
    }
    printf("%d", ans);
    return 0;
}