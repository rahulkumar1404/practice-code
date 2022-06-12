/*
#3 Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1
*/
  //code

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        constexpr int top_limit = INT_MAX/10;
        constexpr int bottom_limit = INT_MIN/10;
        while(x!=0){
            if(rev>top_limit||rev<bottom_limit) return 0;
            
            rev = rev*10+x%10;
          
            x = x/10;
        }
        return rev;
    }
};
