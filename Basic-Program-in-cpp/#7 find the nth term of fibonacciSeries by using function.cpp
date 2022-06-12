// #7 find the nth term of fibonacciSeries by using function.cpp
#include <iostream>

using namespace std;
int fibonacciSeries(int n){
    if(n==1) return 1;
    n = (n-1)+(n-2);
    return n;
}
int main()
{
    int n;
    cout<<"entern the value"<<endl;
    std::cin >> n;
    n = fibonacciSeries(n);
    cout<<"answer = "<<n<<endl;

    return 0;
}
