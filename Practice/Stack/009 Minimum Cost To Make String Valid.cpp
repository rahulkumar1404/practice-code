/*
https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
*/
#include<stack>
int findMinimumCost(string str) {
  // Write your code here
    if(str.length()%2 == 1) return -1;
    int a = 0,b = 0 , ans = 0;
    stack<char> s;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);
        }else{
            if(!s.empty() && s.top() == '{')
                s.pop();
            else s.push(ch);
        }
    }
    while(!s.empty()){
        if(s.top() == '{') a++;
        if(s.top() == '}') b++;
        s.pop();
    }
    ans += (a+1)/2 + (b+1)/2;
    return ans;
}
