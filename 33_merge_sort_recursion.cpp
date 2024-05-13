// https://leetcode.com/problems/sort-an-array/

class Solution {
private: 
    void merge(vector<int> &arr, int s, int e){
        int mid=s+(e-s)/2;
        int len1=mid-s+1;
        int len2=e-mid;

        // creating a new array for the first part
        
        int arrindex=s;
        int *first = new int[len1];
        for(int i=0; i<len1; i++){
            first[i]=arr[arrindex++];
        }

        arrindex=mid+1;
        int *second = new int[len2];
        for(int i=0; i<len2; i++){
            second[i]=arr[arrindex++];
        }

        int i=0, j=0;
        arrindex=s;
        while(i<len1 && j<len2){
            if(first[i]<second[j]){
                arr[arrindex++]=first[i++];
            }
            else{
                arr[arrindex++]=second[j++];
            }
        }

        while(i<len1){
            arr[arrindex++]=first[i++];
        }
        while(j<len2){

            arr[arrindex++]=second[j++];
        }


        delete []first;
        delete []second;
    }
    
    void mergeSort(vector<int> &arr, int s, int e){
        if(s>=e){
            return;
        }
        int mid = s+(e-s)/2;

        //sorting the left part
        mergeSort(arr, s, mid);
        
        //sorting the left part
        mergeSort(arr, mid+1, e);

        //merging the two sorted parts
        merge(arr, s, e);


    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        mergeSort(nums,s,e);
        return nums;
    }
};