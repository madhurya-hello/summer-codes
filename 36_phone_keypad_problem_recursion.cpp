// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
private:
    void find(string digits, string mapping[], string output, int index, vector<string> &ans){
        
        // edge case
        if(digits.length()==0){
            return;
        }

        // base case
        if(index==digits.length()){
            ans.push_back(output);
            return;
        }

        int x=digits[index]-'0';    // ascii values ko substract kar diya
        string str=mapping[x];

        // putting each char of str into separate recursions
        for(int i=0; i<str.length(); i++ ){
            output.push_back(str[i]);
            find(digits, mapping, output, index+1, ans);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string output;
        int index=0;
        find(digits, mapping, output, index, ans);
        return ans;
    }
};
