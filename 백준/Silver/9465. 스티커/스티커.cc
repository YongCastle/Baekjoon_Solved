
#include <iostream>
#include <algorithm>

int sticker[2][100001];
int N;
//       100   1    1   100
//        1    1   100   1
//f(n,0) = score(n,0) + max(score(n-1,1) + f(n-2,0), f(n-2,1))
//f(n,1) = score(n,1) + max(score(n-1,0) + f(n-2,1), f(n-2,0))
//f(n) = max(f(n,0), f(n,1))
int DP[2][100001];
void update(){
    DP[0][0] = 0;
    DP[1][0] = 0;
    
    DP[0][1] = sticker[0][1];
    DP[1][1] = sticker[1][1];

    for(int i=2; i<N+1; i++){
        //If 
        DP[0][i] = sticker[0][i] + 
                    std::max(DP[1][i-1], DP[1][i-2]);
        DP[1][i] = sticker[1][i] + 
                    std::max(DP[0][i-1], DP[0][i-2]);
    }
};

int main()
{
    int T; std::cin>>T;
    for(int i=0; i<T; i++){
        std::cin >> N;
        
        // Step 1 ) Input Data
        for(int j=0; j<2; j++){
            for(int k=1; k<N+1; k++){
                std::cin >> sticker[j][k];
            }
        }
        update();
        // Step 2) Find Maxx
        std::cout<<std::max(DP[0][N], DP[1][N])<<'\n';
    }
    return 0;
}