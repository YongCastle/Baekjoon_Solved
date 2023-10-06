#include <iostream>
#define MAX_NUM 1001

int main(void){
    int N; std::cin >> N;
    int num;
    int ans = 0;
    // Sieve of Eratosthenes
    //                      0      1     2 ...
    bool rprime[MAX_NUM] = {true, true, false};     // default false
    // false : r / true : not prime
    for(int i=2; i<MAX_NUM; i++){
        if(!rprime[i]){
            for(int j=i*2; j<MAX_NUM; j+=i){
                rprime[j] = true;
            }
        }
    }
    // for(int i=0; i<MAX_NUM; i++){
    //     std::cout << i << ':' << rprime[i]<< '\n';
    // }
    // Input Data
    for(int i=0; i<N; i++){
        std::cin >> num;
        if(!rprime[num]){
            ans ++;
        }
    }
    std::cout << ans;
}
