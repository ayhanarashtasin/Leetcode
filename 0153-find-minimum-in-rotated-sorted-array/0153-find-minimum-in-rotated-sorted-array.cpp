class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;
        int minimum = INT_MAX;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[start]<=arr[mid]){
                minimum = min(minimum,arr[start]);
                start = mid+1;
            }
            else{
                minimum = min(minimum,arr[mid]);
                end = mid-1;
            }
        }

        return minimum;
    }
};