#include <iostream>

int main(void){
    int max_val = 0;
    int max_idx = 0;
    int tmp;

    for(int i=0; i<9; i++){
        std::cin>>tmp;
        if(tmp > max_val){
            max_val = tmp;
            max_idx = i;
        }
    }
    std::cout<<max_val<<'\n'<<max_idx+1;
}