class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //we do xor operation in array.
        //then we find the right most bit.
        //if rightmostbit == numbersrightmost==1 then put into bucket1 else bucket2
        long long xorr = 0;
        for(int i=0; i<nums.size(); i++){
            xorr = xorr^nums[i];
        }
        int  rightmostbit = (xorr&xorr-1)^xorr;
        int bucket1=0;
        int bucket2=0;
        for(int i=0; i<nums.size(); i++){
            if ((rightmostbit&nums[i])!=0){
                bucket1 = bucket1^nums[i];
            }
            else{
                bucket2 = bucket2^nums[i];
            }
        }
        return {bucket1,bucket2};
    }
};