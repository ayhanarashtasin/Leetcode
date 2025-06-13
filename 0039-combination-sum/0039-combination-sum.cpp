class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combination_list;
        vector<int>temp;
        comsum(candidates,target,0,temp,combination_list);
        return combination_list;
    }
    void comsum(vector<int>& candidates, int target,int index,vector<int>&temp,vector<vector<int>> &combination_list){
        if(index==candidates.size()){
            if(target==0){
                combination_list.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            comsum(candidates,target-candidates[index],index,temp,combination_list);
            temp.pop_back();
        }
        comsum(candidates,target,index+1,temp,combination_list);
    }
};