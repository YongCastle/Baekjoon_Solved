#include <iostream>
#include <vector>
#include <algorithm>


int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    int N,K; std::cin>>N>>K;
    std::vector<int> arr(N);
    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    std::cout<<arr[K-1];
   
}