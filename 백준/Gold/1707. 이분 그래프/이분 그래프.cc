#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

std::vector<std::vector<int>> adj(20001);
short nodes[20001];     //0 - not visited, 1-blue, -1 - red
int K, V, E;
int u, v;

bool BFS(const int v){
    std::queue<int> candidates;
    candidates.push(v);
    nodes[v] = 1;
    int next;
    int team;
    
    while(!candidates.empty()){
        next = candidates.front();
        candidates.pop();
        team = nodes[next];
        for(auto itr = adj[next].begin(); itr!=adj[next].end(); ++itr){
            if(nodes[*itr] == 0){
                candidates.push(*itr); 
                nodes[*itr] = -1*team;
            }
            else if(nodes[*itr] == team){    //not Bipartite
                return false;
            }
            
        }
    }
    
    return true;
}

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    std::cin>>K;
    while(K--){
        std::cin>>V>>E;
        bool isBipartite = true;
        for(auto itr = adj.begin(); itr!=adj.end(); ++itr)
            itr->clear();
        memset(nodes, 0, sizeof(short)*(V+1));
        for(int i=0; i<E; i++){
            std::cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // Logic
        for(int i=1; i<=V; i++){
            if(nodes[i] == 0){
                if(BFS(i) == false){
                    isBipartite = false;
                    break;
                }
            }
        }
        std::string ans = (isBipartite)? "YES":"NO";
        std::cout<<ans<<'\n';
    }
    
    return 0;
}