// https://leetcode.com/problems/merge-sorted-array/

class Solution {

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2; 
        }
        else if (n==0){
            nums1=nums1;
        }
        else{
            for(int j=0; j<n; j++){
                
                int inserted=0;

                for (int i=m-1+j; i>=0; i--){
          
                    if(nums2[j]>nums1[i]){
                    
                        int e=i+1; // nums2[j] will be inserted at position 'e'
                    
                        // shifting the elements of nums1
                        for(int k=m+n-1; k>e; k--){
                            nums1[k]=nums1[k-1];
                        }
                    
                        // inserting the element
                        nums1[e]=nums2[j];

                        inserted = 1;
                        break;
                    }
                }

                // agar insert huwa hi nahi, matlab ans2[j] is the smallest element and must be placed at index '0'
                if (inserted==0){
                    
                    int e=0; // nums2[j] will be inserted at position '0'
                    
                    // shifting the elements of nums1
                    for(int k=m+n-1; k>e; k--){
                        nums1[k]=nums1[k-1];
                    }
                    
                    // inserting the element
                    nums1[e]=nums2[j];

                }
                

            }
        }
        
    }
};