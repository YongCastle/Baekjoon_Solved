#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



void print_password(std::vector<char> &vec, int L)
{
    std::vector<int> ind;
    for(int i=0; i<L; i++){
        ind.push_back(0);
    }
    for(int i=0; i<vec.size()-L; i++){
        ind.push_back(1);
    }
    std::string str;
    do{
        str.clear();
        int m = 0 ; int j = 0;
        for(int i=0; i<vec.size(); i++){
            if(ind[i]==0){
                str+=vec[i];
                if(vec[i] == 'a' || vec[i] == 'e' || vec[i]== 'i'||vec[i] =='o'||vec[i]=='u'){
                    m++;
                }
                else{
                    j++;
                }
            }
        }
        if(m>=1 && j>=2)
            std::cout<<str<<'\n';
        
    }while(next_permutation(ind.begin(), ind.end()));
}

int main(void){
    int L, C; std::cin>>L>>C;
    std::vector<char> vec;
    char ch;
    for(int i=0; i<C; i++){
        std::cin>>ch;
        vec.push_back(ch);
    }
    std::sort(vec.begin(), vec.end());
    
    print_password(vec, L);
    return 0;
}