#include <cstdio>
#include <stack>
#include <queue>
#include <utility>

std::stack<int> hanoi[4];
std::queue<std::pair<int, int>> ansQ;
int ans=0;

void print_hanoi(){
    printf(" Hanoi state : ");
    for(int i=1; i<=3; i++){
        if(hanoi[i].empty()){
            printf("0 ");
        }
        else{
            printf("%d ", hanoi[i].top());
        }
    }
    printf("\n");
}

bool move(int src, int dst)
{
    if(hanoi[src].empty()){
        printf("There is no hanoi at SRC\n");
        return false;
    }
    int srcVal;
    srcVal = hanoi[src].top();
    hanoi[src].pop();
    
    if(!hanoi[dst].empty() && srcVal > hanoi[dst].top()){
        printf("srcVal is bigger than DST\n");
        return false;
    }
    hanoi[dst].push(srcVal);
    ansQ.push({src, dst});
    ans++;
    return true;
}

void dfs(int size, int src, int dst){
    if(size==0){
        return;
    }
    
    if(dst == 3){
        dfs(size-1, src, 3-src);
        move(src, dst);
        //print_hanoi();
        dfs(size-1, 3-src, dst);
    }
    else if(dst == 2){
        dfs(size-1, src, 4-src);
        move(src, dst);
        //print_hanoi();
        dfs(size-1, 4-src, dst);
    }
    else if(dst == 1){
        dfs(size-1, src, 5-src);
        move(src, dst);
        //print_hanoi();
        dfs(size-1, 5-src, dst);
    }
}

int main(void){
    int N; scanf("%d", &N);
    
    for(int i=N; i>0; i--){
        hanoi[1].push(i);
    }
    //print_hanoi();
    dfs(N, 1, 3);
    
    printf("%d\n", ans);
    while(!ansQ.empty())
    {
        auto p = ansQ.front();
        ansQ.pop();
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}