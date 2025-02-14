class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>v;
        v[0]=-1;
        int prefix_sum=0;
        for(int i=0; i<nums.size(); i++){
            prefix_sum+=nums[i];
            if(v.find(prefix_sum%k)==v.end()){
                v[prefix_sum%k]=i;
            }
            else{
                if(i-v[prefix_sum%k]>1){
                    return true;
                }
            }
        }
        return false;
    }
};