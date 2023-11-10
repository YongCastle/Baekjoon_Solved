#include <iostream>

int fib_1[41];
int fib_0[41];

// fib[3] = fib[2] + fib[1];
// fib[0] = 1 0
// fib[1] = 0 1 
// fib[2] = 1 1
// fib[3] = 1 2

int main(void){
    int T;
    fib_0[0] = 1; fib_1[0] = 0;
    fib_0[1] = 0; fib_1[1] = 1;
    for(int i=2; i<41; i++){
        fib_0[i] = fib_0[i-1]+fib_0[i-2]; 
        fib_1[i] = fib_1[i-1]+fib_1[i-2];
    }
    
    std::cin>>T;
    int N;
    for(int i=0; i<T; i++){
        std::cin>>N;
        std::cout<<fib_0[N]<<' '<<fib_1[N]<<'\n';
    }
    
    return 0;
}