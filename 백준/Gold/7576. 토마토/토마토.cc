#include <cstdio>
#include <tuple>
#include <queue>
#define MAX_W 1000

//          ^  >  v  <
int M, N;
int dn[] = {-1, 0, 1, 0};
int dm[] = {0, 1, 0, -1};
int box[MAX_W][MAX_W];

int bfs(std::queue<std::tuple<int, int, int, int>> &multiQueue){
    int mm, nn, depth, color;
    int cnt=0;
    
    while(!multiQueue.empty())
    {
        auto tmp = multiQueue.front();
        multiQueue.pop();
        int n = std::get<0>(tmp);
        int m = std::get<1>(tmp);
        depth = std::get<2>(tmp);
        color = std::get<3>(tmp);
        
        box[n][m] = color;
        
        for(int i=0; i<4; i++){
            mm = m + dm[i];
            nn = n + dn[i];
            
            //Check Out of Bound
            if(mm < 0 || nn < 0 || mm > M-1 || nn > N-1){
                continue;
            }
            
            if(box[nn][mm] == 0){
                box[nn][mm] = color;
                multiQueue.push(std::make_tuple(nn, mm, depth+1, color));
            }
        }
    }
    return depth;
}

int main(void){
    scanf("%d %d", &M, &N);
    
    bool allDone = 1;
    //n, m, d, color
    std::queue<std::tuple<int, int, int, int>> multiQueue;
    
    int color = 2;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            scanf("%d", &box[n][m]);
            if(box[n][m] == 0){
                allDone = 0;
            }
            else if(box[n][m] == 1){
                multiQueue.push(std::make_tuple(n, m, 0, color++));
            }
        }
    }
    if(allDone){
        printf("0");
        return 0;
    }
    
    int ans = bfs(multiQueue);
   
    //check all allDone
    allDone = 1;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            if( box[n][m] == 0){
                allDone = 0;
            }
        }
    } 

    ans = (allDone)? ans:-1;
    printf("%d", ans);
    return 0;
}