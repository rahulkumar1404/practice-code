// https://leetcode.com/problems/permutation-in-string/
class Solution {
private:
    bool checkEqual(int a[26],int b[26]){
        for(int i = 0;i<26;i++){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        int n1 = s1.length();
        int n2 = s2.length();
        for(int i = 0;i<n1;i++){
            int index = s1[i]-'a';
            count1[index]++;
        }
        int i = 0;
        int count2[26]={0};
        while(i<n1&&i<n2){
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }
        if( checkEqual(count1,count2) ) return 1;
        while(i<n2){
            char newChar = s2[i];
            int index = newChar-'a';
            count2[index]++;
            char oldChar = s2[i-n1];
            index = oldChar - 'a';
            count2[index]--;
            i++;
            if( checkEqual(count1,count2) ) return 1;
        } 
        return 0;
    }
};
