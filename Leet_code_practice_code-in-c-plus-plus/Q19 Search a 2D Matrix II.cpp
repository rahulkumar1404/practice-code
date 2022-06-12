https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size();
        int j = matrix[0].size();
        int s = 0;
        int e = j-1;
        
        while(s<i && e>=0){
            int ele = matrix[s][e];
            if(ele==target) return 1;
            else if(ele<target) s++;
            else e--;
            
        }
        return 0;
    }
};
