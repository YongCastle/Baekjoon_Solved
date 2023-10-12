#include <iostream>
#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(0);       // Seperate Stream 
    std::cin.tie(0); std::cout.tie(0);  // Dont Flush ! - Unsync
    
    int arr[1001] = {1001, 0,};
    int DP_D[1001] = {0, 0,};
    int ans = -1;
    
    int N; std::cin >> N;
    
    // Find Descend Bytonic
    for(int i=1; i<N+1; i++){       // i : pivot
        std::cin >> arr[i];
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]){
                DP_D[i] = (DP_D[i] < DP_D[j]+1)? DP_D[j]+1 : DP_D[i];
            }
        }
        
        if(ans < DP_D[i]){
            ans = DP_D[i];
        }
    }

    std::cout << ans;
    
    return 0;
}