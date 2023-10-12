#include <iostream>
#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);       // Seperate Stream 
    std::cin.tie(0); std::cout.tie(0);  // Dont Flush ! - Unsync
    
    int arr[1001] = {0, };
    int DP_U[1001] = {0, };
    int DP_D[1001] = {0, };
    int ans = -1;
    
    int N; std::cin >> N;
    
    // Find Ascend Bytonic
    // O(n^2 / 2)
    for(int i=1; i<N+1; i++){       //pivot
        std::cin >> arr[i];
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                DP_U[i] = (DP_U[i] < DP_U[j]+1)? DP_U[j]+1 : DP_U[i];
            }
        }
    }
    // Find Descend Bytonic
    // O(n^2 / 2)
    for(int i=N; i>0; i--){         //pivot
        for(int j=N; j>i; j--){
            if(arr[i] > arr[j]){
                DP_D[i] = (DP_D[i] < DP_D[j]+1)? DP_D[j]+1 : DP_D[i];
            }
        }
        if (ans < DP_U[i] + DP_D[i]){
            ans = DP_U[i] + DP_D[i];
        }
    }
    
    std::cout << ans;
    
    return 0;
}