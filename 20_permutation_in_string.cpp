// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
private:
    bool isEqual(int count1[], int count2[]){
        for(int i=0; i<26; i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.length(), n=s2.length();
        
        // edge case
        if(m>n){
            return false;
        }
        
        // counting letters in s1
        int count1[26]={0};
        for(int i=0; i<m; i++){
            int k=s1[i]-'a'; // converting char to integer
            count1[k]++;
        }

        // searching in s2
        int count2[26]={0};
        int i=0;
        while (i<m){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }

        if(isEqual(count1,count2)){
            return true;
        }
        else{
            
            while(i<n){
                int index=s2[i]-'a'; // new character
                count2[index]++;
                index=s2[i-m]-'a'; // old character
                count2[index]--;
                i++;
                if(isEqual(count1,count2)){
                    return true;
                }


            }
            return false;
        }
    }
};