/*
https://www.codingninjas.com/codestudio/contests/love-babbar-contest-6/4329939/problems/18911?leftPanelTab=0
*/

int chooseMaxStudents(vector<int> &h, int n) {
    // Write your code here
    int count = 0;
    sort(h.begin(),h.end());
    int j = 0;
    for(int i = 0;i<n;i++){
        if(h[i] - h[j] > 5)
            j++;
        count = max(count,i-j+1);
    }
    
    return count;
}
