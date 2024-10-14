class Solution {
public:
    int findfirstpart(vector<int>& nums,int end , int target){
        int start = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    int findsecondpart(vector<int>& nums,int start , int  target){
        int end = nums.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    int findpivot(vector<int>& nums){
        int start = 0;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid<end && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid>start && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            else if(nums[start]>=nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return {};
    }
    int search(vector<int>& nums, int target) {
        int pivot = findpivot(nums);
        int first = findfirstpart(nums,pivot,target);
        if (first==-1){
            int second = findsecondpart(nums,pivot+1,target);
            return second;
        }
        else{
            return first;
        }
    }
};