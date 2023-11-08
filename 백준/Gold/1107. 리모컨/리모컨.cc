#include <iostream>
#include <vector>
#define ABS(N) (((N)>0)? (N) : -(N))
#define MIN(A, B) (((A)<(B))? (A):(B))

//              0  1  2  3  4  5  6  7  8  9
int btns[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int N, M, tmp;
std::vector<int> vec;
int curr = 100;
int ans = 987654321;

int dfs(int sum, int digits, int num){
    if(digits == 0){
        //std::cout<<sum<<"  "<<num<<'\n';
        return ABS(N-num);
    }

    int tmp = 987654321;
    for(auto &itr : vec){

        tmp = MIN(tmp, dfs(sum, digits-1, (num)*10+itr));
    }
    return tmp;
}

void findNearest(int N, int digits){
    if(digits<0){
        return;
    }
    else if(digits == 0){
        ans = MIN(ans, ABS(N-100));
        return;
    }
    //std::cout<<digits<<' '<<dfs(digits, digits, 0)<<'\n';
    ans = MIN(digits + dfs(digits, digits, 0), ans);
    return;
}

void jmp2Near(int N)
{
    // ------------ Step 1) Find # of digits
    int digits = 0;
    for(int i=N; i>0; i/=10){
        digits++;
    }
    // ------------ Step 2)
    //findNearest(N, digits+1);
    findNearest(N, digits);
    //std::cout<<"ans:"<<ans<<'\n';
    findNearest(N, digits-1);
    //std::cout<<"ans:"<<ans<<'\n';
    findNearest(N, digits+1);
    //std::cout<<"ans:"<<ans<<'\n';
}


int main(void){
    
    std::cin>>N>>M;
    for(int i=0; i<M; i++){
        std::cin>>tmp;
        btns[tmp] = 0;
    }
    for(int i=0; i<10; i++){
        if(btns[i] == 1)
        {
            vec.push_back(i);
        }
    }
    //--------- Logic --------------
    // Step 1) Find nearest N and jmp!
    jmp2Near(N);

    // Step 2) Compare!
    ans = MIN(ans, ABS(N-100));
    
    std::cout<<ans;

    return 0;   
}