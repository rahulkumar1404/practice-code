/*
https://www.codingninjas.com/codestudio/contests/love-babbar-contest-3/3743976/problems/14474?leftPanelTab=1
*/

int minimumNet(int n, int k, vector<bool> fish)
{
    // Write your code here.
    int count = 0;
    vector<int> index;
    for(int i = 0;i<n;i++){
        if(fish[i] == true){
            index.push_back(i);
            count++;
        }
    }
    if(count<k) return -1;
    int ans = n;
    int j = 0;
    for(int i = k-1;i<count;i++){
        ans = min(ans,index[i] - index[j]+1);
        j++;
    }
    return ans;
}
