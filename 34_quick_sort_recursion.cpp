class Solution {
private: 
    int partition(vector<int> &nums, int start, int end){
        
        int pivot=nums[start];
        
        // finding the pivot index
        int count=0;
        for(int i=start+1; i<=end; i++){
            if(nums[i]<=pivot){
                count++;
            }
        }
        int pivotIndex=start+count;
        
        // placing the element at pivot index
        swap(nums[pivotIndex], nums[start]);

        // handling the left and right part
        int x=start, y=end;
        while(x<pivotIndex && y>pivotIndex){
            while(nums[x]<=pivot){
                x++;
            }
            while(nums[y]>pivot){
                y--;
            }
            if(x<pivotIndex && y>pivotIndex){
                swap(nums[x++], nums[y++]);
            }
        }
        return pivotIndex;
    }
    
    void quickSortBaby(vector<int> &nums, int start, int end){
        
        if(start>=end){
            return ;
        }
        
        int pivotIndex=partition(nums, start ,end);
        
        quickSortBaby(nums, start, pivotIndex-1);
        quickSortBaby(nums, pivotIndex+1, end);


    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        quickSortBaby(nums, start, end);
        return nums;
    }
};