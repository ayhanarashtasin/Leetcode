class Solution {
public:
    int maximum(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long findtotalhour(vector<int>& piles,int hour){
        long long totalhour = 0;
        for(int i=0; i<piles.size(); i++){
            totalhour+=ceil((double)piles[i]/(double)hour);
        }
        return totalhour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = maximum(piles);
        while(start<=end){
            int mid = start+(end-start)/2;
            long long totalhour = findtotalhour(piles,mid);
            if(totalhour<=h){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return start;
    }
};