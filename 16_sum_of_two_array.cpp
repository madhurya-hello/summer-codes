// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size();
        vector<int> ans;
        int carry=0;
        for (int i=n-1; i>=0; i--){
            carry=carry+num[i]+(k%10);
            ans.push_back(carry%10);
            carry=carry/10;
            k=k/10;
        }
        int remain=carry+k;
        while(remain!=0){
            ans.push_back(remain%10);
            remain=remain/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};