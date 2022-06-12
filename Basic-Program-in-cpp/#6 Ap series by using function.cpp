//A.p SERIES 
#include <iostream>

using namespace std;

int ap(int a ,int b,int n){
    int d = b-a;
    n = a+(n-1)*d;
    return n;
}

int main()
{
    int a,b,n;
    std::cout << "Enter the first number" << std::endl;
    std::cin >> a;
    std::cout << "Enter the second number" << std::endl;
    std::cin >> b;
    std::cout << "Enter the last term for output" << std::endl;
    std::cin >> n;
    int ans = ap(a,b,n);
    std::cout << "answer = "<<ans << std::endl;
    return ans;
}
