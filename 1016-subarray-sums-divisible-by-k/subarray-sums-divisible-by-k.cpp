class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>prefix(n+1);

        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        map<int,int>mp;
        mp[prefix[0]]=1;
        int ans=0;
        for(int i=1; i<=n; i++){
            int target = prefix[i]%k;
            if(target<0){
                target = target+k;
            }
            if(mp.find(target)!=mp.end()){
                ans+=mp[target];
            }
            mp[target]++;
        }
        return ans;
    }
};