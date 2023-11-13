// https://www.acmicpc.net/problem/9019
//9019
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>

typedef std::queue<std::tuple<std::string, int, int>> qtsii;
typedef std::tuple<std::string, int, int> tsii;

int Dop(int A){
    return (A*2 > 9999)? (2*A)%10000 : 2*A;
}
int Sop(int A){
    return (A != 0)? A-1 : 9999;
}
int Lop(int A){
    int d[4] = {0,};
    int idx;
    // 4321 -> 4 3 2 1
    for(int i=3; i>=0; i--){
        idx = (i-1>=0)? i-1:3;
        d[idx] = A % 10;
        A /= 10;
    }
    int sum=0;
    for(int i=0; i<4; i++){
        sum*=10;
        sum+=d[i];
    }
    return sum;
}
int Rop(int A){
    int d[4] = {0,};
    int idx;
    // 4321 -> 4 3 2 1
    for(int i=3; i>=0; i--){
        idx = (i+1>3)? 0:i+1;
        d[idx] = A % 10;
        A /= 10;
    }
    int sum=0;
    for(int i=0; i<4; i++){
        sum*=10;
        sum+=d[i];
    }
    return sum;
}

std::string BFS(int A, int B)
{
   std::queue<std::tuple<std::string, int, int>> Q;
   bool visited[10000];
   Q.push(std::make_tuple("", A, 0));
   memset(visited, false, sizeof(bool)*10000);
   visited[A]=true;
   int N, depth, D, S, L, R;
   std::string ans;
   while(!Q.empty()){
        auto T = Q.front(); Q.pop();
        std::string &str = std::get<0>(T);
        N = std::get<1>(T);
        depth = std::get<2>(T);
        //std::cout<<"t : "<<N<<'\n';
        if(N == B){
            ans = str;
            break;
        }
        D = Dop(N); S = Sop(N); L = Lop(N); R = Rop(N);
        
        if(visited[D] == false){
            Q.push(std::make_tuple(str+"D", D, depth+1));
        }
        if(visited[L] == false){
            Q.push(std::make_tuple(str+"L", L, depth+1));
        }
        if(visited[R] == false){
            Q.push(std::make_tuple(str+"R", R, depth+1));
        }
        if(visited[S] == false){
            Q.push(std::make_tuple(str+"S", S, depth+1));
        }
        
        visited[D] = true;
        visited[S] = true;
        visited[L] = true;
        visited[R] = true;
   }
   
   return ans;
}

int main(void){
    
    int T; std::cin>>T;
    int A, B;
    std::string str;
    for(int i=0; i<T; i++){
        std::cin>>A>>B;
        std::cout<<BFS(A,B)<<'\n';
    }
    
    return 0;
}