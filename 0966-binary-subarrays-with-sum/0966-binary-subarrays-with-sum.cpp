class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int>prefix(n+1);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        map<int,int>mp;
        mp[prefix[0]]++;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(mp.find(prefix[i]-goal)!=mp.end()) ans+=mp[prefix[i]-goal];
            mp[prefix[i]]++;
        }
        return ans;
    }
};