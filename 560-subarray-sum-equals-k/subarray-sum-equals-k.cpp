class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int>prefix(n+1,0);

        for(int i=0; i<nums.size(); i++){
            prefix[i+1] = prefix[i] + nums[i]; 
        }
        int ans = 0;
        map<int,int>mp;
        mp[prefix[0]] = 1;
        for(int i=1; i<=nums.size(); i++){
            if(mp.find(prefix[i]-k)!=mp.end()) ans+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return ans;
    }
};