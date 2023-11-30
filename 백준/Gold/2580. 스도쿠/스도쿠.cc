#include <iostream>
#include <vector>
#include <utility>

std::vector<int> empty;
std::vector<int> find_candidates(int (*arr)[10], int x, int y){
    std::vector<int> candidates(10, 0);
    candidates[0] = 1;
    //Horizontal
    for(int i=1; i<10; i++){
        if(arr[x][i] != 0){
            if((candidates[arr[x][i]] & 0b1) == 0b1){
                //std::cout<<"HOR"<<'\n';
                return empty;
            }
            else{
                candidates[arr[x][i]] |= 0b1;
            }
        }
    }
    //Vertical
    for(int i=1; i<10; i++){
        if(arr[i][y] != 0){
            if((candidates[arr[i][y]] & 0b10) == 0b10){
                //std::cout<<"Ver"<<'\n';
                return empty;
            }
            else{
                candidates[arr[i][y]] |= 0b10;
            }
        }
    }
    
    //Rectangle
    for(int i=((x-1)/3)*3+1; i<((x-1)/3)*3+1+3; i++){
        for(int j=((y-1)/3)*3+1; j<((y-1)/3)*3+1+3; j++){
            if(arr[i][j] != 0){
                if((candidates[arr[i][j]] & 0b100) == 0b100){
                    //std::cout<<"Rec"<<'\n';
                    return empty;
                }
                else{
                    candidates[arr[i][j]] |= 0b100;
                }
            }
        }
    }
    
    return candidates;
}

bool DFS(int (*arr)[10], std::vector<std::pair<int, int>> vp){
    if(vp.empty()){
        return true;
    }
    
    auto P = vp.back(); vp.pop_back();
    std::vector<int> candidates = find_candidates(arr, P.first, P.second);
    if(candidates.empty()){
        return false;
    }
    else{
        int idx=0;
        for(auto &candidate : candidates){
            if(candidate == 0){
                //std::cout<<'\n'<<idx<<'\n';
                arr[P.first][P.second] = idx;
                if(DFS(arr, vp)){
                    return true;
                }
                else{
                    arr[P.first][P.second] = 0;
                }
            }
            idx++;
        }
    }
    
    return false;
}

int main(void){
    int arr[10][10];
    std::vector<std::pair<int, int>> vp;
    
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            std::cin>>arr[i][j];
            if(arr[i][j] == 0){
                vp.push_back({i, j});    
            }
        }
    }
    //=====================================

    DFS(arr, vp);
    
    //=====================================
    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            std::cout<<arr[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    
    
    return 0;
}