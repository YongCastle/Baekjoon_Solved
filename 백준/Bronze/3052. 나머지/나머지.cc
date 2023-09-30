#include <iostream>


int main(void){

    int num;
    int res_arr[42] = {0,};  // 0 ~ 41
    int ans = 0;

    // Make Rest
    for(int i=0 ; i<10; i++){
        std::cin>>num;
        res_arr[num % 42] += 1;
    }
    // Find Rest
    for(int i=0; i<42; i++){
        if(res_arr[i] != 0){
            ans+=1;
        }
    }
    std::cout<<ans;

}