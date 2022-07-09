/*
https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/3583551/problems/14818
*/
int LightUptheStreet(int n, int m , int k , vector <int> Checkpoints){
    // Write Code here.
    int maxi = 0,l =0;
    int ans = 0;
    for(int i:Checkpoints){
        if(i-k-1>l){
            if(i-k-1>maxi){
                ans = -1;
                break;
            }
            ans++;
            l = maxi;
        }
        maxi = i + k;
    }
    if(l<n){
        if(maxi<n) ans = -1;
        else ans++;
    }
    return ans;
}

