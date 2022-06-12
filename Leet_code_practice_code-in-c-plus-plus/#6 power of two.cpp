/*#6 power of two
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

//code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for(int i=0;i<=30;i++){
            if(ans==n){
                return true;
            }
            if(ans < INT_MAX/2)
            ans = ans * 2;
            
        }
        return false;
    }
};
