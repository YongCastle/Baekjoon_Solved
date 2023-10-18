#include <cstdio>
#include <vector>


void print(int N, int B){
    if(N == 0){
        return;
    }
    
    int rst = N % B;
    int tmp = (rst >= 10)? (rst-10)+'A' : rst+'0';
    print(N/B, B);
    printf("%c", tmp);
}

int main(void){
    int N, B;
    scanf("%d %d", &N, &B);
    
    int rst;
    char tmp;
    
    print(N, B);
    
    return 0;
}