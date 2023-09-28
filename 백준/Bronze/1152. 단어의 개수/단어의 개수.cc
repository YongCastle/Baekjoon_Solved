#include <string>
#include <iostream>


int main(void){
    std::string str;
    int i = 0;
    int numOfWord = 0;
    getline(std::cin, str);
    int len = str.length();

    if(str[0] != ' '){
        numOfWord++;
    }

    for(int i = 1; i < len; i++){
        if(str[i-1] == ' ' && str[i] != ' '){
            numOfWord++;
        }
    }
    std::cout<<numOfWord;

    return 0;
}