#include <iostream>
#include <string>
#define MAX_ITEMS 10000

template <typename T>
class MyStack {
private:
    T *arr;
    int top;
public:
    MyStack();       // 생성자
    ~MyStack();      // 소멸자

    bool push(const T item);
    T pop();
    int size() const;
    bool empty() const;
    T top_num() const;
};

template <typename T>
MyStack<T>::MyStack() {
    arr = new T[MAX_ITEMS];
    top = -1;
}

template <typename T>
MyStack<T>::~MyStack() {
    delete[] arr;
}

template <typename T>
bool MyStack<T>::push(const T item) {
    if (top >= MAX_ITEMS - 1)
        return false;
    arr[++top] = item;
    return true;
}

template <typename T>
T MyStack<T>::pop(){
    if(top == -1){
        return -1;
    }
    return arr[top--];
}

template <typename T>
int MyStack<T>::size() const {
    return top + 1;
}

template <typename T>
bool MyStack<T>::empty() const {
    return (top == -1);
}

template <typename T>
T MyStack<T>::top_num() const {
    if (top == -1)
        return -1;
    return arr[top];
}

int main(void) {
    std::ios::sync_with_stdio(0);

    int N;
    std::cin >> N;
    std::string command;
    int X;

    MyStack<int> myStack;

    for (int i = 0; i < N; i++) {
        std::cin >> command;
        int result;
        if (command == "push") {
            std::cin >> X;
            myStack.push(X);

        }
        else{
            if (command == "pop") {
                result = myStack.pop();

            } else if (command == "size") {
                result = myStack.size();
    
            } else if (command == "empty") {
                result = myStack.empty();
    
            } else if (command == "top") {
                result = myStack.top_num();
            }
            std::cout << result << '\n';
        }
    }

    return 0;
}
