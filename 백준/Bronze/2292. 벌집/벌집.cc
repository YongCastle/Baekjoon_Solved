#include <iostream>

int main()
{
    // 1 -> 6 -> 6*2 -> 6*3 -> 6*4 ->
    int N; std::cin>>N;
    int i = 1;
    int cnt = 0;
    N-- , cnt ++;
    while (N> 0){
        N -= 6*i , i++;
        cnt++;
    }
    std::cout << cnt;
    return 0;
}