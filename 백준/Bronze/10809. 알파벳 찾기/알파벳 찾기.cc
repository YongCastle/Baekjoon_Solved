#include <iostream>
#include <cstring>
#define MAX 100
int main(void){
    int arr[26];
    for(int i=0 ; i<26; i++){
        arr[i] = -1;
    }
    char str[101];
    int len = 0;

    std::cin>>str;
    len = strlen(str);
    //the Others
    for(int i=0 ; i<len; i++){
        if(arr[str[i]-'a'] == -1){
            arr[str[i]-'a'] = i;
        }
    }
    for(int i=0 ; i<25; i++){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<arr[25];
}
