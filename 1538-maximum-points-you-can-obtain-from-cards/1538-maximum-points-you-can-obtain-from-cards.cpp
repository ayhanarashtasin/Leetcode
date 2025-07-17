class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0;
        int r=cardPoints.size()-1;
        int sum1=0;
        int sum2=0;
        while(l<k){
            sum1+=cardPoints[l];
            sum2+=cardPoints[r];
            l++;
            r--;
        }
        l--;
        r=cardPoints.size()-1;
        int maxpoints=max(sum1,sum2);
        int i=0;
        int dual_sum=0;
        while(i<k){
           sum1-=cardPoints[l];
           sum1+=cardPoints[r];
           maxpoints = max(maxpoints,sum1);
           l--;
           r--;
           i++;
        }
        maxpoints = max(maxpoints,sum1);
        return maxpoints;
    }
};