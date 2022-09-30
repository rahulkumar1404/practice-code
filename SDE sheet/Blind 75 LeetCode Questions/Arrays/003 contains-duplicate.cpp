/*
https://leetcode.com/problems/contains-duplicate/submissions/
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool isDuplicate = false;
        unordered_map<int,int> m;
        
        for(int i = 0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>1){
                isDuplicate = true;
                break;
            }
        }
        return isDuplicate;
    }
};
