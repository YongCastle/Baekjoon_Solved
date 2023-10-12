#include <iostream>
#include <bits/stdc++.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))


int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    int N; std::cin>>N;
    int arr[301];
    int DP[301][2];
    
    std::cin>>arr[0]>>arr[1];
    DP[0][0] = arr[0];          //[i][0] : prev step is not Done
    DP[0][1] = arr[0];          //[i][1] : prev step is Done
    DP[1][0] = arr[1];
    DP[1][1] = arr[0] + arr[1];
    // DP[i, 1] = arr[i] + DP[i-1, 0]
    // DP[i, 0] = arr[i] + max(DP[i-2, 0], DP[i-2, 1])
    for(int i=2; i<N; i++){
        std::cin >> arr[i];
        DP[i][1] = arr[i] + DP[i-1][0];
        DP[i][0] = arr[i] + MAX(DP[i-2][1], DP[i-2][0]);
    }

    std::cout << MAX(DP[N-1][1], DP[N-1][0]);
    
    return 0;
}