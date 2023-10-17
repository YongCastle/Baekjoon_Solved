#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void){
    int N; std::cin>>N;
    
    std::deque<int> dq;
    int X;
    while(N--){
        string command;
        std::cin>>command;
        
        if(command == "push_front"){
            std::cin >> X;
            dq.push_front(X);
        }
        else if(command == "push_back"){
            std::cin >> X;
            dq.push_back(X);
        }
        else if(command == "pop_front"){
            if(!dq.empty()){
                std::cout<<dq.front()<<'\n';
                dq.pop_front();
            }
            else{
                std::cout<<-1<<'\n';
            } 
        }
        else if(command == "pop_back"){
            if(!dq.empty()){
                std::cout<<dq.back()<<'\n';
                dq.pop_back();
            }
            else{
                std::cout<<-1<<'\n';
            }   
        }
        else if(command == "size"){
            std::cout<<dq.size()<<'\n';
        }
        else if(command == "empty"){
            if(!dq.empty())
                std::cout<<0<<'\n';
            else
                std::cout<<1<<'\n';
        }
        else if(command == "front"){
            if(!dq.empty())
                std::cout<<dq.front()<<'\n';
            else
                std::cout<<-1<<'\n';
        }
        else if(command == "back"){
            if(!dq.empty())
                std::cout<<dq.back()<<'\n';
            else
                std::cout<<-1<<'\n';
        }
    }
    
    return 0;
}