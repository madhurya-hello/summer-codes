// https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // method 1: just locate the zeroes and use the bubble-sort-technique to drag them to the end
        // method 2:
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                int optimisation=0;
                for(int j=i+1; j<nums.size(); j++){
                    if(nums[j]!=0){
                        // swap
                        int temp=nums[j];
                        nums[j]=nums[i];
                        nums[i]=temp;
                        optimisation=1;
                        break;
                    }
                }
                if(optimisation==0){
                    break;
                }

            }
        }
    }
};