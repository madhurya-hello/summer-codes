// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();
        int start=0;
        int end=(row*column)-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if (target==matrix[mid/column][mid%column]){
                return true;
            }
            else if (target>matrix[mid/column][mid%column]){
                start=mid+1;
            }
            else if(target<matrix[mid/column][mid%column]){
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return false;
    }
};