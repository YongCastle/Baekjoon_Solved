#include <iostream>

//1 0 ? ? ? ? ? ?
// f(n) = f(n-2) + f(n-3) + .. + f(1) + 1
long long arrLL[91] = {1, 1, 1, };  // f(0) = 1

int main(void){
    int N; std::cin>>N;
    long long sumLL = arrLL[0];
    for(int i=3; i<N+1; i++){
        sumLL += arrLL[i-2];
        arrLL[i] = sumLL;
    }
    std::cout << arrLL[N];

    return 0;
}