#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <utility>

//          ^  >  v   <
int d[] = {-3, 1, 3, -1};

// 0 ~ 8 : data / 9: zpos
int main(void){
    std::string str;
    char tmp;
    char zpos;
    for(int i=0; i<9; i++){
        std::cin>>tmp;
        if(tmp=='0'){
            zpos = i+'0';
        }
        str.push_back(tmp);
    }
    str.push_back(zpos);
    std::map<std::string, int> Hash_Table;
    Hash_Table[str] = 0;
    
    
    std::queue<std::pair<std::string, int>> Q;

    Q.push({str, 0});
    while(!Q.empty()){
        auto &P = Q.front();
        int depth_i = P.second;
        std::string &prev = P.first;
        
        // std::cout<<prev[0]<<' '<<prev[1]<<' '<<prev[2]<<'\n';
        // std::cout<<prev[3]<<' '<<prev[4]<<' '<<prev[5]<<'\n';
        // std::cout<<prev[6]<<' '<<prev[7]<<' '<<prev[8]<<'\n';
        // std::cout<<depth_i<<"\n\n";

        
        if(prev == "1234567808"){
            std::cout<<depth_i;
            return 0;
        }
        if(prev[9] == 1 ||prev[9] == 4 || prev[9] ==7){
            int d[] = {-3, 1, 3, -1};
        }
        for(int i=0; i<4; i++){
            int nz_i = prev[9]-'0' + d[i];
            if(prev[9] == '2' && nz_i == 3 || prev[9] == '5' && nz_i == 6){
                continue;
            }
            if(prev[9] == '3' && nz_i == 2 || prev[9] == '6' && nz_i == 5){
                continue;
            }
            if(nz_i < 0 || nz_i > 8){
                continue;    
            }
            std::string next = prev; //copy
            // if(next[nz_i]-'0' == nz_i+1)
            //     continue;
            next[prev[9]-'0'] = next[nz_i];
            next[nz_i] = '0';
            next[9] = nz_i+'0';
            
            // std::cout<<next<<'\n';
            // std::cout<<Hash_Table[next]<<"\n\n";
            if(Hash_Table[next] == 0 || Hash_Table[next] > depth_i+1 )
            {
                Hash_Table[next] = depth_i + 1;
                Q.push({next, depth_i+1});
            }
        }
        Q.pop();
    }
    
    std::cout<<-1;
    
    return 0;
}