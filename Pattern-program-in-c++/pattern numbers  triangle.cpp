/*
Number triangle which is equal to the number of rows 
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
        while(col<=row){
            std::cout << " "<<row<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }

    return 0;
}
