
#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int N, K;
    std::cin >> N >> K;
    
    std::queue<int> Q;
    for(int i=1; i<=N; i++){
        Q.push(i);
    }
    
    int arr[5000];
    int cnt=0;
    while(!Q.empty()){
        for(int i=1; i<K; i++){
            Q.push(Q.front());
            Q.pop();
        }
        arr[cnt++] = Q.front();
        Q.pop();
    }
    std::cout<<'<'<<arr[0];
    for(int i=1; i<N; i++){
        std::cout<<", "<<arr[i];
    }
    std::cout<<'>';
    return 0;
}
