#include <iostream>
#include <stack>
#include <string>

int main(void){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    int N; std::cin>>N;
    
    std::string input;
    for(int i=0; i<N; i++){
        std::cin>>input;
        
        std::stack<char> myStack;
        int cnt = 0;
        
        std::string answer = "YES";
        while(input[cnt] != '\0'){
            if(input[cnt] == ')'){
                if (!myStack.empty() && myStack.top() == '(')
                    myStack.pop();
                else{
                    answer = "NO";
                    break;
                }
            }
            else{
                myStack.push(input[cnt]);
            }
            cnt ++;
        }
        
        if(!myStack.empty()){
            answer = "NO";
        }
        
        std::cout<<answer<<'\n';
    }
}