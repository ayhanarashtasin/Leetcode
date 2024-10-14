class Solution {
public:
    int firstindex(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int first = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if (nums[mid]==target){
                first = mid;
                right = mid-1;
            }
            else if(target>nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return first;
    }
    int secondindex(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int second = -1;
        while(left<=right){
            int mid = left+ (right-left)/2;
            if(nums[mid]==target){
                second = mid;
                left = mid+1;
            }
            else if(target>nums[mid]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstindex(nums,target);
        int second = secondindex(nums,target);
        return {first,second};
    }
};