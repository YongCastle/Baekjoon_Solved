#include <iostream>

void update(int *arr){
    int prev = arr[0];
    arr[0] = arr[1];
    for(int i=1; i<9; i++){
        int newValue = prev + arr[i+1];
        if(newValue>1e9){
            newValue = newValue % 1000000000;
        }
        prev = arr[i];
        arr[i] = newValue;
    }
    arr[9] = prev;
}

int main() {
    int N; std::cin>>N;

    //             0  1  2  3  4  5  6  7  8  9 
    int arr[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int i=1; i<N; i++){
        update(arr);
    }
    int ans=0;
    for(int i=1; i<10; i++){
        ans += arr[i];
        ans = ans % 1000000000;
        //std::cout<<arr[i]<<'\n';
    }
    std::cout<<ans;
    return 0;
}
