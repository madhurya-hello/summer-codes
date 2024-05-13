// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();    // n = row = column

        // Step1: find transpose
        for (int i=0; i<n; i++)        {
            int j=0;
            while(i!=j){
                int temp;
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
                j++;
            }
        }

        // Step 2: reverse the rows
        for(int i=0; i<n; i++){
            int start=0;
            int end=n-1;
            while(start<end){
                int temp;
                temp=matrix[i][start];
                matrix[i][start]=matrix[i][end];
                matrix[i][end]=temp;
                start++;
                end--;
            }

        }

    }
};

