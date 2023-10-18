#include <cstdio>

// A>B
long long GCM(const long long ALL, const long long BLL){
    long long H, L;
    H = ALL;
    L = BLL;
    
    return (H%L==0)? L:GCM(L, H%L);
}



int main(void){
    long long ALL, BLL;
    scanf("%lld %lld", &ALL, &BLL);

    long long H, L;
    H = (ALL < BLL)? BLL:ALL;
    L = (ALL < BLL)? ALL:BLL;
    
    long long ans = GCM(H,  L);
    while(ans-- >0){
        printf("%c",'1');
    }
    
    return 0;
}