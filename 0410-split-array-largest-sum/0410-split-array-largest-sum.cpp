class Solution {
public:
    int sum(vector<int>& nums){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        return sum;
    }
    int maximum(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(nums[i],maxi);
        }
        return maxi;
    }
    int findminimum(vector<int>& nums , int val){
        int split = 1;
        int minimum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]+minimum<=val){
                minimum+=nums[i];
            }
            else{
                split+=1;
                minimum = nums[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = maximum(nums);
        int end = sum(nums)-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            int split = findminimum(nums,mid);
            if(split<=k){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};