class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (nums[i]^ones) & ~(twos); //if number not in twos that means its single and we store it ones.
            twos = (nums[i]^twos) & ~ones; //if number not in ones that means its more than once so we store it twos.
        }
        return ones;
    }
};