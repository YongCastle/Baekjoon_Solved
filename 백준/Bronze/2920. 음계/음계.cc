#include <iostream>

int main(void){
    int arr[8]; int i;
    for(i=0; i<8; i++){
        std::cin>>arr[i];
    }

    if (arr[0] == 1){
        //Check Ascending
        i = 0;
        for(i=0; i<8; i++){
            if(arr[i] != i+1){
                break;
            }
        }

        if(i==8)    std::cout<<"ascending";
        else        std::cout<<"mixed";
    }
    else if (arr[0] == 8){
        i = 0;
        for(i=0; i<8; i++){
            if(arr[i] != 8-i){
                break;
            }
        }

        if(i==8)    std::cout<<"descending";
        else        std::cout<<"mixed";
    }
    else{
        std::cout<<"mixed";
    }

    return 0;
}