#include <iostream>

int GCM(const int Hi, const int Lo){
    int H = Hi;
    int L = Lo;
    if (H%L!=0){
        return GCM(L, H%L);
    }
    else{
        return L;
    }
}

int main(void){
    std::ios::sync_with_stdio(0);
    
    int T; std::cin>>T;
    int A, B;
    int tmp;
    for(int i=0; i<T; i++){
        std::cin>>A>>B;
        if(A<B){
            tmp = A;
            A = B;
            B = tmp;
        }
        std::cout<<A*(B/GCM(A,B))<<'\n';
    }
    
    return 0;
}