class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        int minimum_rounds=0;
        for(auto &it:mp){
            if(it.second==1){
                return -1;
            }
            if(it.second%3==0){
                minimum_rounds+=it.second/3;
            }
            else{
                minimum_rounds+=(it.second/3) +1;
            }
        }
        return minimum_rounds;
    }
};