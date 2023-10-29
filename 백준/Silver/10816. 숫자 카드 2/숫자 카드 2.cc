#include <cstdio>
#include <algorithm>
#include <unordered_map>

std::unordered_map<int, int> deck;

int main(void){
    int N; scanf("%d", &N);
    int tmp=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &tmp);
        deck[tmp] = deck[tmp] + 1;  //O(log N)
    }
    
    int M; scanf("%d", &M);
    for(int i=0; i<M; i++){
        scanf("%d", &tmp);
        printf("%d ", deck[tmp]);
    }
    
    return 0;
}