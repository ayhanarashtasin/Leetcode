/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findfirstpart(MountainArray &mountainArr,int end , int target){
        int start = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(target>mountainArr.get(mid)){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
    int findsecondpart(MountainArray &mountainArr,int start , int  target){
        int end = mountainArr.length()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(mountainArr.get(mid)==target){
                return mid;
            }
            else if(target>mountainArr.get(mid)){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(start==end){
                int value = findfirstpart(mountainArr,start,target);
                if(value!=-1){
                    return value;
                }
                else{
                    int value1 = findsecondpart(mountainArr,start,target);
                    if (value1!=-1){
                        return value1;
                    }
                    else{
                        return -1;
                    }
                }
            }
            else if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        return {};
    }
};