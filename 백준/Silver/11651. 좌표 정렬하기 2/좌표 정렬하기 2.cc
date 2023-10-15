
#include <iostream>
#include <algorithm>

struct Point
{
    int xPos;
    int yPos;
};

bool comparePoint(const Point& a, const Point& b)
{
    if (a.yPos != b.yPos){
        return a.yPos < b.yPos;
    }
    else
    {
        return a.xPos < b.xPos;
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    
    int N; std::cin>>N;
    Point * arr = new Point[N];
    for(int i=0; i<N; i++){
        std::cin>>arr[i].xPos>>arr[i].yPos;
    }
    std::stable_sort(arr, arr+N, comparePoint);
    
    for(int i=0; i<N; i++){
        std::cout<<arr[i].xPos<<' '<<arr[i].yPos<<'\n';
    }
    
    delete[] arr;
    return 0;
}