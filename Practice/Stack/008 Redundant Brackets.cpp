/*
https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0
*/
#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }else{
            if(ch == ')'){
                bool isRedundant = true;
                while(st.top() != '(' ){
                    char temp = st.top();
                    if( temp == '+' || temp == '-' || temp == '*' || temp == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) return true;
                else st.pop();
            }
        }
    }
    return false;
}
