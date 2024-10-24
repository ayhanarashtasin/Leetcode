class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int subset = (1<<nums.size());
        for(int i=0; i<subset; i++){
            vector<int>temp;
            for(int j=0; j<nums.size(); j++){
                if( (i &(1<<j))!=0){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};