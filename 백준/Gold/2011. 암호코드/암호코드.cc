#include <iostream>
#define DIV 1000000

//                                       <=       <=
inline int charToInt(const char *arr, int start, int end){
    int sum = 0;
    for(int i=start; i<end+1; i++){
        sum *= 10;
        sum += int(arr[i]) - int('0');
    }
    return sum;
};

int DP[5001] = {0, };
bool update(const char *password, const int start, const int end){
    // start <= i <= end
    DP[0] = 1;  //None

    DP[1] = 1;  //DP[n] <-> password[n-1]
    for(int i=2; i<end+1; i++){
        if(password[i] == '0'){    
            if(password[i-1] == '0'){
                return false;
            }  
            if(password[i-1]<='2'){     // Case -  20  
                DP[i] = DP[i-2];
            }
            else{                       // Case -  30
                return false;
            }
            continue;
        }
        if(password[i-1] == '0'){    // Case - 03
            DP[i] = DP[i-1];
            continue;
        }
        int tmp = charToInt(password, i-1, i);
        if(tmp-1<=25){
            DP[i] = DP[i-1] + DP[i-2];
        }
        else{
            DP[i] = DP[i-1];
        }
        DP[i] = DP[i] % DIV;
    }
    return true;
};

int main(void){
    char password[5002];
    std::cin.getline(&password[1], sizeof(password)-sizeof(char));
    password[0] = ' ';
    if(password[1] == '0'){
        std::cout<<0;
        return 0;
    }
    int i=0;
    while(password[i++]!='\0');
    int start = 1;
    int end = i-2;
    if(!update(password, start, end)){
        std::cout<<0;
        return 0;
    }
    // std::cout<<'\n';
    // for(int i=0; i<end+1; i++){
    //     std::cout << password[i] <<' ';
    // }
    // std::cout<<'\n';
    // for(int i=0; i<end+1; i++){
    //     std::cout << DP[i] <<' ';
    // }
    // std::cout<<'\n';
    std::cout<<DP[end];
    
    return 0;
}