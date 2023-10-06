#include <iostream>
#define N_SIZE 7

int main(void){

    // Step 1) Input
    int N; std::cin>>N;
    int arr[N_SIZE] = {0, };
    int tmp = N; int i = 0;
    do{
        arr[i++] = tmp % 10;
        tmp = int(tmp/10);
    }while (tmp != 0);
    i -= 1;     // Idx

    // Step 2) Logic
    int start_num = N - arr[i] - 9*i;
    int sum;
    for (int k = start_num; k<N; k++){
        sum = k;
        tmp = k;
        do{
            sum += tmp % 10;
            tmp = int(tmp/10);
        }while (tmp != 0);

        if(sum == N){
            std::cout<<k;
            return 0;
        }
    
    }
    std::cout << 0;

    return 0;
}