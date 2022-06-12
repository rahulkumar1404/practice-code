//done by rahul kumar
#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    long n; //why not taken as int because when we put a large value it will return error or other unexpected answer because 2^31-1;
    std::cout << "Enter the number for conversion" << std::endl;
    std::cin >> n;
    int res = 0, i=0;
    if(n<0){
            n = -1*n;// converteed in 1's complement
        }
    while(n!=0){
        long bit = n&1; //it will match the last bit of the number whether is 0 or 1;
        res = (bit * pow(10,i))+res; //it will store the result of digits in resvers order;
        n>>=1; //left shift means n divided by 2;
        i++;
    }
    std::cout << "Your requested answer : "<<(~res+1)*-1 << std::endl;//it will convert 2's complement
    return 0;
}
