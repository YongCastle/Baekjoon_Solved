#include <iostream>

int main(void){
    long long DP[100] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 0};
    // f(n) = f(n-1) + f(n-5);
    
    int T; std::cin >>T;
    int *arr = new int[T];
    int max = 0;
    for(int i=0; i<T; i++){
        std::cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    //Update
    for(int i=10; i<max+1; i++){
        DP[i] = DP[i-1] + DP[i-5];
    }
    
    for(int i=0; i<T; i++){
        std::cout<<DP[arr[i]]<<'\n';
    }
    return 0;
}