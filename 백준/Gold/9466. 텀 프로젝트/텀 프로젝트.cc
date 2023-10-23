#include <cstdio>
#include <cstring>
#include <vector>


int students[100001];
int visited[100001];
/*
*   -1 : rst
*    0 : non-visited
*  >=1 : team 
*/


int makeTeam(int N)
{
    int rst = 0;
    for(int i=1; i<=N; i++){
        if(visited[i]==0){
            std::vector<int> vec;
            vec.push_back(i);
            bool isEnd=false;
            while(!isEnd)
            {
                int curr = vec.back();
                if(visited[curr] != 0){
                    //find uncycle
                    for(auto j=0; j<vec.size(); ++j){
                        if(vec[j] == curr)
                        {
                            isEnd = true;
                            break;
                        }
                        else{
                            visited[vec[j]] == -1;
                            rst++; 
                        }
                    }
                }
                else{
                    visited[curr] = i;
                    vec.push_back(students[curr]);
                }
            }
        }
        else{
            continue;
        }
    }
    
    return rst;
}


int main(void){
    int T; scanf("%d", &T);
    int N;
    while(T--)
    {
        scanf("%d", &N);
        memset(visited+1, 0, sizeof(int)*100000);
        // Input Data
        for(int i=1; i<=N; i++){
            scanf("%d", &students[i]);
        }
        
        printf("%d\n", makeTeam(N));
    }
    
    return 0;
}