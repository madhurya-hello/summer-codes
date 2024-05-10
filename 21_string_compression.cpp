// https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
       
       // if only one element is present
       if(chars.size()==1){
        return 1;
       }

       // if more than one element is present
       int i=0, j=1, z=0; 
       int count=1;
       while(i<chars.size()){
        while(j<chars.size()){
            if(chars[i]==chars[j]){
                count++;
                j++;
            }
            else{
                break;
            }
        }
        chars[z++]=chars[i];
        if(count>1){
            // converting a number to string
            string st=to_string(count);
            for(char ch: st){
                chars[z++]=ch;
            }
            
        }
        i=j;
        j++;
        count=1;

        // when i reaches the last element and j++ does not exist
        if(i==chars.size()-1){
            chars[z++]=chars[i];
            break;
        }
       }
       return z;
    }
};