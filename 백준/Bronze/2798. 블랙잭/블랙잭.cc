#include <iostream>
#include <cstdlib>

int main(void){
    int N, M; std::cin>>N>>M;
    int arr[100];

    for(int i=0; i<N; i++){
        std::cin>>arr[i];
    }
    int ans = 0;
    int ans_abs = M;
    int tmp_abs, tmp_ans;

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N ; k++){
                tmp_ans = arr[i] + arr[j] + arr[k];
                tmp_abs = abs(tmp_ans - M);
                if(tmp_abs == 0){
                    std::cout << tmp_ans;
                    return 0;
                }
                if(tmp_ans <= M && tmp_abs < ans_abs){
                    ans_abs = tmp_abs;
                    ans = tmp_ans;
                }
            }
        }
    }

    std::cout<<ans;
    return 0;
}