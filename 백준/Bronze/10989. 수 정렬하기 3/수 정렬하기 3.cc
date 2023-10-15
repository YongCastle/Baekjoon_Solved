#include <iostream>
#include <stdint.h>


int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int N; std::cin>>N;
    // 10^5 x 8B = 0.8MB
    int cntOfNums[10001] = {};

    int tmp;
    int max = 0;
    int min = 10001;
    for(int i=0; i<N; i++){
        std::cin >> tmp;
        cntOfNums[tmp]+= 1;
        if(tmp > max){
            max = tmp;
        }
        if(tmp < min){
            min = tmp;
        }
    }

    for(int i=min; i<max+1; i++){
        for(int j=0; j<cntOfNums[i]; j++){
            std::cout<<i<<'\n';
        }
    }

    return 0;
}