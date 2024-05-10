// https://leetcode.com/problems/spiral-matrix/description/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int column=matrix[0].size();
        int top=0, bottom=row-1, left=0, right=column-1;
        vector<int> output;
        int total=row*column;
        int count=0;

        while(count<total){
            
            // printing the top row
            for(int i=left; i<=right; i++){
                output.push_back(matrix[top][i]);
                count++;
                if(count==total){
                    return output;
                }
            }
            top++;

            // printing the right column
            for(int i=top; i<=bottom; i++){
                output.push_back(matrix[i][right]);
                count++;
                if(count==total){
                    return output;
                }
            }
            right--;

            // printing the bottom row
            for (int i=right; i>=left; i--){
                output.push_back(matrix[bottom][i]);
                count++;
                if(count==total){
                    return output;
                }
            }
            bottom--;

            // printing the left column
            for(int i=bottom; i>=top; i--){
                output.push_back(matrix[i][left]);
                count++;
                if(count==total){
                    return output;
                }
            }
            left++;
        }
        return output;
    }
};
