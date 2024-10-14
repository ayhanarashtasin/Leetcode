class Solution {
public:
    int maximum(vector<int>& nums){
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    long long finddivisor(vector<int>& nums,int divisor){
        long long lessthanthreshold = 0;
        for(int i=0; i<nums.size(); i++){
            lessthanthreshold+=ceil((double)nums[i]/(double)(divisor));
        }
        return lessthanthreshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = maximum(nums)-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            long long value = finddivisor(nums,mid);
            if(value<=threshold){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};