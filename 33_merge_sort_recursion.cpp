// https://leetcode.com/problems/sort-an-array/

class Solution {
private: 
    void merge(vector<int> &arr, int s, int e){
        int mid=s+(e-s)/2;
        int len1=mid-s+1;
        int len2=e-mid;

        // creating a new temporary array for the first part

        int arrindex=s;
        int *first = new int[len1];
        for(int i=0; i<len1; i++){
            first[i]=arr[arrindex++];
        }

        // creating a new temporary array for the second part

        arrindex=mid+1;
        int *second = new int[len2];
        for(int i=0; i<len2; i++){
            second[i]=arr[arrindex++];
        }

        // merging the two arrays

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

        // copying the remaining elements of first array in case first array is larger than second array

        while(i<len1){
            arr[arrindex++]=first[i++];
        }

        // copying the remaining elements of second array in case second array is larger than first array

        while(j<len2){

            arr[arrindex++]=second[j++];
        }

        // deleting both the temporary arrays
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