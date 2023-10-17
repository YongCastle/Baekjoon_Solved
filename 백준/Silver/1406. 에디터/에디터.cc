#include <iostream>
#include <list>
#include <string>

int main(void){
    std::ios::sync_with_stdio(0);
    //std::cin.tie(0), std::cout.tie(0);
    
    std::list<char> editor;
    std::string init; std::cin>>init;
    for(int i=0; i<init.length(); i++){
        editor.push_back(init[i]);
    }
    
    std::list<char>::iterator itr = editor.end();
    int N; std::cin>>N;
    while(N--){
        std::string ch;
        std::cin>>ch;
        
        if(ch == "L"){
            if(itr != editor.begin()){
                itr--;   
            }
        }
        else if(ch == "D"){
            if(itr != editor.end()){
                itr++;   
            }
        }   
        else if(ch == "B"){
            if(itr != editor.begin()){
                itr--;
                itr = editor.erase(itr);
            }
        }
        else if(ch == "P"){
            char tmp;
            std::cin>>tmp;
            
            editor.insert(itr, tmp);
        }
    }
    
    for(std::list<char>::iterator it = editor.begin(); it != editor.end(); it++){
        std::cout << *it;
    }
}