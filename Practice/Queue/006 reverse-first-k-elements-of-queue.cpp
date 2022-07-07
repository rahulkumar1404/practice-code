/*
https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    //step1 : fetch k element and put into stack
    stack<int> s;
    for(int i = 0;i<k;i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    //ste2 :fetech all element in stack and put into queue
    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    //step3: fetch n-k element and remove from first and put into back of queue
    int temp = q.size() - k;
    while(temp--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
