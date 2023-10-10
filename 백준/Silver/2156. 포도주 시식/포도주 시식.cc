#include <iostream>
#include <algorithm>
// f(n, 1) = score(n) + max(score(n-1) + f(n-2, 0), f(n-2, 1))
// f(n, 0) = f(n-1, 1)
// f(n) = max(f(n, 1), f(n, 0))
// 6 10 13 9 8 1
int arr[10001];
int DP[10001][2];

void update(int n){
    DP[1][0] = 0;
    DP[1][1] = arr[1];
    DP[2][0] = arr[1];
    DP[2][1] = arr[2] + arr[1];
    for(int i=3; i<n+1; i++){
        DP[i][1] = arr[i] + std::max(arr[i-1]+DP[i-2][0], DP[i-2][1]);
        DP[i][0] = std::max(DP[i-1][1], DP[i-1][0]);
    }
    // for(int i=1; i<n+1; i++){
    //     std::cout<<DP[i][1]<<' ';
    // }
    // std::cout<<'\n';
    // for(int i=1; i<n+1; i++){
    //     std::cout<<DP[i][0]<<' ';
    // }
    // std::cout<<'\n';
};

int main(void){
    int n; std::cin>>n;

    for(int i=1; i<n+1; i++){
        std::cin >> arr[i];
    }
    update(n);
    std::cout<<std::max(DP[n][1], DP[n][0]);
}