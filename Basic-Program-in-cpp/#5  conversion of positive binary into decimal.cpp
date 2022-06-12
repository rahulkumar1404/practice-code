//done by rahul kumar
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    long n; //enter the binary digit to decimal
    std::cout << "Enter the bnary digit for conversion" << std::endl;
    std::cin >> n;
    int res = 0, i=0;
    while(n!=0){
        long digit = n%10; //it will store the last bit of the number as remainder is 0 or 1;
        res = (digit * pow(2,i))+res; //it will store the result of digits in resvers order;
        n=n/10; //iteration for division means n divided by 10;
        i++;
    }
    std::cout << "Your requested answer : "<<res << std::endl;//it will convert 2's complement
    return 0;
}
