/*
pattern

 A  B  C  D  E 
 B  C  D  E  F 
 C  D  E  F  G 
 D  E  F  G  H 
 E  F  G  H  I 

*/
//code:
#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cin >> n;
    int row = 1;
    while(row<=n){
        int col = 1;
        while(col<=n){
            char ch = 'A' + row + col - 2;
            cout<<" "<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}
