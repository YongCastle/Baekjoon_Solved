#include <iostream>


int main(void){
    int A;
    std::cin >> A;

    for(int i=1; i<A+1; i++){
        for(int j=0; j<i; j++){
            std::cout<<'*';
        }
        std::cout << '\n';
    }
}