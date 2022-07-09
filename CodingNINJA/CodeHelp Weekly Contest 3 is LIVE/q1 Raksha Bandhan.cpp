/*
https://www.codingninjas.com/codestudio/contests/love-babbar-contest-3/3743976/problems/14474
*/
int rakshaBandhan(vector < int > arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int i = n-1;
    int ans = 0, sum = 0;
    while(i>=0){
        sum += arr[i];
        if(sum <=0) break;
        ans++;
        i--;
    }
    return ans;
}
