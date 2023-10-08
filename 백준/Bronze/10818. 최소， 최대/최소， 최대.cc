#include <iostream>

int main(void){
    int N; std::cin>>N;
    int tmp;
    int min = 1000000;
    int max = -1000000;
    for(int i=0; i<N; i++){
        std::cin>>tmp;
        if(tmp<min)
            min = tmp;
        if(tmp>max)
            max = tmp;
    }
    std::cout<<min<<' '<<max;
    return 0;
}