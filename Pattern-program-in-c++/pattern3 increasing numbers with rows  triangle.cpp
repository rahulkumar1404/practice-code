/*
pattern 
1
2 3
4 5 6
7 8 9 10
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cin >> n;
    int row = 1;
    while(row<=n){
        int col = 1;
        int value = row;
        while(col<=row){
            std::cout <<" "<<value<<" ";
            value = value+1;
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}
