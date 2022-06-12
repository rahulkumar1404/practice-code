//problem link https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isValid(char ch){
	if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9') return true;
	else return false;
    }
    char tolower(char ch){
        if(ch>='a'&&ch<='z'||ch>='0'&&ch<='9') return ch;
        else {
            char temp = ch-'A'+'a';
            return temp;
        }
    }
    bool isPalindrome(string s) {
        int i =0;
        int j = s.length()-1;
        while(i<=j){
            if(!isValid(s[i])) i++;
            else if(!isValid(s[j])) j--;
            else{

                if(tolower(s[i]) !=tolower(s[j])){
                     return false;
                }else{
                    i++;
                    j--;
                }
            }
        }
        return true;
    }
};
