#include <cstdio>
#include <cstring>
#define MAX_N 50

//            ^  >  v  <   9  3  1  7
int dw[] = { 0, 1, 0,  -1, 1, 1, -1, -1};
int dh[] = { -1, 0, 1, 0, -1, 1, 1, -1};
int graph[MAX_N][MAX_N];
int W, H;
int ans;
int color;

void dfs(int h, int w, int color){
    
    int hh, ww;
    graph[h][w] = color;
    
    for(int i=0; i<8; i++){
        hh = h + dh[i];
        ww = w + dw[i];
        if(hh < 0 || hh > H-1 || ww < 0 || ww > W-1){
            // out of bound
            continue;
        }
        if(graph[hh][ww]==1){
            dfs(hh,ww,color);
        }
    }
};

int main(void){
    while(scanf("%d %d", &W, &H), W!=0){
        
        //Reset
        memset(graph, 0, sizeof(int)*MAX_N*MAX_N);
        ans = 0; color = 2;
        
        //Input
        for(int h=0; h<H; h++){
            for(int w=0; w<W; w++){
                scanf("%1d", &graph[h][w]);
            }
        }
        
        //Logic
        for(int h=0; h<H; h++){
            for(int w=0; w<W; w++){
                if(graph[h][w] == 1){
                    ans++;
                    dfs(h, w, color++);
                }
            }
        }
        printf("%d\n" , ans);
    }
    
    
    return 0;
}