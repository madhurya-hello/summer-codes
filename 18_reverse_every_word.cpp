// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
private:
    void reverse(string &s, int start, int end){
        while(start<end){
            char temp;
            temp=s[end];
            s[end]=s[start];
            s[start]=temp;
            start++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        int start=0, end=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                end=i-1;
                reverse(s,start,end);
                start=i+1;
            }
            else if(i==s.length()-1){
                end=i;
                reverse(s,start,end);
            }
        }
        return s;
    }
};