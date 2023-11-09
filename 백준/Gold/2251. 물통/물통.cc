#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

typedef std::array<int, 4> arr;

std::vector<int> ans;

int capa[4];    // Capa
std::map<arr, int> memory;

void move(arr &bottles, int src, int dst)
{
    if(bottles[src] == 0){
        return;
    }
    
    if(bottles[src] > (capa[dst]-bottles[dst])){
        bottles[src] = bottles[src] - (capa[dst]-bottles[dst]);
        bottles[dst] = capa[dst];
    }
    else{
        bottles[dst] = bottles[dst]+bottles[src];
        bottles[src] = 0;
    }
}

void dfs(arr bottles, int src, int dst, int rst){
    move(bottles, src, dst);
    //Memorization Pruning
    if(memory[bottles] != 0){
        return;
    }
    //std::cout<< bottles[1] <<' '<<bottles[2]<<' '<<bottles[3]<<'\n';
    memory[bottles] = 1;
    //End Condition
    if(bottles[1] == 0){
        memory.insert({bottles, 1});
        ans.push_back(bottles[3]);
    }
    dfs(bottles, src, rst, dst);
    dfs(bottles, src, dst, rst);
    dfs(bottles, dst, rst, src);
    dfs(bottles, dst, src, rst);
    dfs(bottles, rst, src, dst);
    dfs(bottles, rst, dst, src);
    
    return;
}


int main(void){
    std::cin>>capa[1]>>capa[2]>>capa[3];  //Capa
    arr bottles;  // water
    bottles[1]=0, bottles[2]=0, bottles[3]=capa[3];
    
    ans.push_back(capa[3]);
    memory[bottles] = 1;
    //std::cout<< bottles[1] <<' '<<bottles[2]<<' '<<bottles[3]<<'\n';
    dfs(bottles, 3, 1, 2);
    dfs(bottles, 3, 2, 1);
    
    std::sort(ans.begin(), ans.end());
    
    for(size_t i = 0; i < ans.size(); ++i) {
        std::cout << ans[i];
        if (i != ans.size() - 1) {
            std::cout << ' ';
        }
    }

    return 0;
}