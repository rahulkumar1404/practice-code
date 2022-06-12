/*
Pattern 
1234554321
1234**4321
123****321
12******21
1********1

code
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
        int first_triangle = n+1-row;
        while(col<=first_triangle){
            cout<<col<<"";
            col++;
        }
        int star = 1;
        while(star<=2*row-2){
            cout<<"*"<<"";
            star++;
        }
        col= col-1;
        while(col>=1){
            cout<<col<<"";
            col--;
        }
        cout<<endl;
        row++;
    }
    return 0;
}
