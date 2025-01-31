class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int distance = abs(arr[1]-arr[0]);
        for(int i=0; i<arr.size()-1; i++){
            if (abs(arr[i+1]-arr[i])!=distance){
                return false;
            }
        }
        return true;
    }
};