// https://leetcode.com/problems/subsets/description/

class Solution {
private:
    void findSubset(vector<int> nums, vector<vector<int>> &ans, vector<int> sub, int size, int index){
        
        if(index==size){
            ans.push_back(sub);
            return;
        }


        // exclude
        findSubset(nums, ans, sub, size, index+1);

        // include
        sub.push_back(nums[index]);
        findSubset(nums, ans, sub, size, index+1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        int size=nums.size();
        findSubset(nums, ans, sub, size, 0);
        return ans;
    }
};