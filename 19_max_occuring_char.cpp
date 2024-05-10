// https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int map[26]={0};
        for(int i=0; i<str.length(); i++){
            
            map[str[i]-'a']++;
        }
        
        int max=0;
        char ans;
        for(int i=0; i<26; i++){
            if(map[i]>max){
                max=map[i];
                ans = 'a' + i;
            }
        }
        
        
        return ans;
    }

};