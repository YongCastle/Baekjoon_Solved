#include <cstdio>
#include <algorithm>
#include <vector>


int main(void){
    std::vector<int> vec;
    
    int N; scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    
    std::sort(vec.begin(), vec.end());
    
    int sum = 0;
    for(int i=N; i>0; i--){
        sum += i*vec[N-i];
    }
    
    printf("%d", sum);
    
    return 0;
}