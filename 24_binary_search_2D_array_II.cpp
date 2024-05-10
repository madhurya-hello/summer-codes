// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();
        int left=0, top=0;
        int right=column-1;
        int bottom=row-1;
        while(right>=0 && top<=row-1){
            if (target==matrix[top][right]){
                return true;
            }
            else if(target>matrix[top][right]){
                top++;
            }
            else if(target<matrix[top][right]){
                right--;
            }
        }
        return false;
    }
};