#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"entern the number"<<endl;
    std::cin >> n;
    
    int a=0;
    int b=1;
    cout<<"Fibonacci series"<<endl;
    cout<<a<<" "<<b<<" ";
    for(int i=1;i<=n;i++){
        int nextNum = a+b;
        a=b;
        b= nextNum;
        std::cout << nextNum << " ";
    }
    return 0;
}
