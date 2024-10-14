class Solution {
public:
    int sum(vector<int>& weights){
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            sum+=weights[i];
        }
        return sum;
    }
    int maximum(vector<int>& weights){
        int maxi = INT_MIN;
        for(int i=0; i<weights.size(); i++){
            maxi = max(maxi,weights[i]);
        }
        return maxi;
    }
    int findday(vector<int>& weights , int capacity){
        int day = 1;
        int load = 0;
        for(int i=0; i<weights.size(); i++){
            if(weights[i]+load>capacity){
                day+=1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = maximum(weights);
        int end = sum(weights)-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int day = findday(weights,mid);
            if(day<=days){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};