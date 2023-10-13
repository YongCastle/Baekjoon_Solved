#include <cstdio>

inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int DP[100001] = {0, 1, 2};

int findMinCount(int N){
    if(N == 0){
        return 0;
    }
    else if(DP[N] != 0){
        return DP[N];    
    }
    int minCount = N;
    for(int i=1; i*i <= N; i++){
        int tmp = findMinCount(N-i*i)+1;
        if(tmp == 2){
            DP[N] = 2;
            return 2;
        }
        minCount = min(tmp, minCount);
    }
    DP[N] = minCount;
    
    return DP[N];
};

int main()
{
    int N; scanf("%d", &N);
    for(int i=1; i*i<=N; i++){
        DP[i*i] = 1;
    }

    printf("%d", findMinCount(N));

    return 0;
}