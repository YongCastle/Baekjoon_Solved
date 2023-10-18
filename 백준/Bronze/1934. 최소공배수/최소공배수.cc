#include <cstdio>

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
    int T; scanf("%d", &T);
    int A, B;
    int tmp;
    for(int i=0; i<T; i++){
        scanf("%d %d", &A, &B);
        if(A<B){
            tmp = A;
            A = B;
            B = tmp;
        }
        printf("%d \n",A*(B/GCM(A,B)));
    }
    
    return 0;
}