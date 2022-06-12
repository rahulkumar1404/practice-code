// #8 count setbits in an integer  by using function.cpp
#include <iostream>

using namespace std;
int setbits(int n){
    
    int count = 0;
    while(n){
        count += n&1;
        n>>=1;
    }
    return count;
}

int main()
{
    int n;
    cout<<"entern the value"<<endl;
    std::cin >> n;
    n = setbits(n);
    cout<<"answer = "<<n<<endl;

    return 0;
}
