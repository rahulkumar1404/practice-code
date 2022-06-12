*/
  pattern
  A
  B B
  C C C
  D D D D
*/
//CODE:
#include <iostream>

using namespace std;

int main()
{
    int n;
    std::cin >> n;
    int row = 1;
    while(row<=n){
        int col = 1;\
        while(col<=row){
            char ch = 'A' + row - 1;
            cout<<" "<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
    return 0;
}
