#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> low;
std::vector<int> high;
int ans = 0;

int main(void){
    int N; std::cin>>N;
    
    int tmp;
    for(int i=0; i<N; i++){
        std::cin>>tmp;
        if(tmp > 0)
            high.push_back(tmp);
        else
            low.push_back(tmp);
    }
    
    std::sort(high.begin(), high.end(), [](const int i, const int j){return i>j;});
    std::sort(low.begin(), low.end());
    
    int buf;
    int cnt = 0;

    for(auto element : low)
    {
        if(cnt==1){
            cnt--;
            ans+= buf*element;
        }
        else{
            cnt++;
            buf = element;
        }
    }
    
    if(cnt==1){
        ans += buf;
    }
    
    // + to > 1
    cnt = 0;
    for(auto element : high){
        //std::cout<<"element:"<<element<<"  ans:"<<ans<<'\n';
        if(element > 1)
        {
            if(cnt==1){
                cnt--;
                ans+= buf*element;
            }
            else{
                cnt++;
                buf = element;
            }
        }
        else{
            if(cnt==1){
                cnt--;
                ans += buf + element;
            }
            else{
                ans+=element;
            }
        }
    }
    if(cnt==1){
        ans+=buf;
    }

    std::cout<< ans;
    return 0;
}