#include <cstdio>
#include <vector>
#include <utility>

std::vector<std::pair<int, short>> tree[100001];
int visited[100001] = {0, };

int max_length = -1;
int e, w;
int dfs(int node){

    int depth1st=0;
    int depth2nd=0;
    int e, w;
    int isleaf = true;
    for(std::pair<int, short> p : tree[node]){
        e = p.first;
        if(visited[e] == 1){
            //printf("already visited %d\n", e);
            continue;
        }
        //printf("At node : %d --> DFS(%d) \n", node, e);
        visited[e] = 1 ;
        w = dfs(e) + p.second;
        //printf("At edge to %d, weight : %d\n", e, w);
        if(w){
            if(depth1st < w){
                depth2nd = depth1st;
                depth1st = w;
            }
            else if(depth2nd < w){
                depth2nd = w;
            }
        }
        isleaf = false;
    }
    if(isleaf){
        //printf("leaf : %d\n", node);
        return 0;   
    }
    
    int sum = depth1st+depth2nd;
    max_length = (max_length > sum)? max_length : sum;
    
    //printf("max len : %d | max depth : %d \n", max_length, (depth1st > depth2nd)? depth1st : depth2nd);
    return (depth1st > depth2nd)? depth1st : depth2nd;
}




int main(void){
    int N; scanf("%d", &N);
    
    // ------------------- STEP 1 ) INPUT -----------------------
    int v, e;
    short w;
    for(int i=0; i<N; i++){
        scanf("%d", &v);
        
        while(scanf("%d", &e), e!=-1){
            scanf("%hd", &w);
            tree[v].push_back(std::make_pair(e, w));
        }
    }
    
    // ------------------- STEP 2 ) LOGIC ------------------------
    visited[1] = 1 ;
    dfs(1);
    
    printf("%d", max_length);
    
    return 0;
}