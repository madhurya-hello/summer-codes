// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i=0, j=s.size()-1; i<j; i++, j--){
            char temp=s[j];
            s[j]=s[i];
            s[i]=temp;
        }
    }
};