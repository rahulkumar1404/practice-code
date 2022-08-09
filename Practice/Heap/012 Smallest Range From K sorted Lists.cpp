/*
https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
*/
#include<bits/stdc++.h>
class Node{
    public:
        int data;
        int row;
        int col;
        
        Node(int d,int r,int c){
            data = d;
            row = r;
            col = c;
        }
};
class compare{
    public:
        bool operator()(Node* a,Node* b){
            return (a->data > b->data);
        }
};
int kSorted(vector<vector<int>> &a, int k, int n) { 
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue< Node* , vector<Node*> , compare > minHeap;
    
    for(int i = 0;i<k;i++){
        int ele = a[i][0];
        mini = min(mini,ele);
        maxi = max(maxi,ele);
        minHeap.push(new Node(a[i][0] , i , 0));
    }
    
    int s = mini , e = maxi;
    
    while( !minHeap.empty() ){
        Node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;
        
        if(maxi - mini < e - s){
            s = mini;
            e = maxi;
        }
        
        if(temp->col + 1 < n ){
            maxi = max(maxi , a[temp->row][temp->col + 1]);
            minHeap.push(new Node(a[temp->row][temp->col + 1] , temp->row,temp->col + 1));
        }else 
            break;
    }
    return (e-s+1);
}
