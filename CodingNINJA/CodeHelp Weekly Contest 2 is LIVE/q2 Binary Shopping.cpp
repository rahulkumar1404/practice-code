/*
https://www.codingninjas.com/codestudio/contests/love-babbar-contest-ii/3583551/problems/14818
*/
string binaryShopping(string S, int P)
{
    // Write your code here.   
    int n = S.size();
    int onecount = 0;
    for(int i = 0;i<n;i++){
        if(S[i] == '1') onecount++;
    }
    if(onecount == 0 || n==1) return S;
    if(onecount == 1){
        S[0] = '1';
        for(int i = 1;i<n;i++){
            S[i] = '0';
        }
    }
    else{
        int zerocount = 0;
        for(int i = n-1;i>=0;i--){
            if(S[i] == '1'){
                S[i] = '0';
                zerocount++;
            }
            if(zerocount == 2) break;
        }
    }
    return S;
}
