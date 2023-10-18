#include <iostream>
#include <string>

int main(void){
    
    std::string str;
    std::cin>>str;
    
    int rst = str.length()%3;
    int tmp = 0;
    //process rst 1 2 3
    for(int i=0; i<rst; i++){
        tmp *= 2;
        tmp += (str[i]-'0');
    }
    if(rst != 0)
        std::cout<<tmp;
    
    for(int i=rst; i<str.length(); i+=3){
        tmp = 0;
        for(int j=i; j<i+3; j++){
            tmp *= 2;
            tmp += (str[j]-'0');
        }
        std::cout<<tmp;
    }
    
    return 0;
}