#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cout << "enter the number for check the Prime number" << std::endl;
    std::cin >> n;
    bool isPrime = 1;
    for (int i=2;i<n;i++) {
        if(n%i==0){
            isPrime = 0;
            break;
        }
    }
    if(isPrime==0){
        cout<<"Not a Prime number = "<<n<<endl;
    }else if(isPrime==1) {
            cout<<"Yes! Prime number = "<<n<<endl;
        }
    return 0;
}
