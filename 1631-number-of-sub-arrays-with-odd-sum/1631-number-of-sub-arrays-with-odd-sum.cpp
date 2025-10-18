class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddcount = 0, evencount = 0, ans = 0, sum = 0;
        long long mod = 1e9 + 7;  // correct modulo (not 1e10 + 7)

        for (int i = 0; i < arr.size(); i++) {
            sum = (sum + arr[i]) % mod;
            if (sum % 2 == 1) {
                ans = (ans + 1 + evencount) % mod;
                oddcount++;
            } else {
                ans = (ans + oddcount) % mod;
                evencount++;
            }
        }
        return ans % mod;
    }
};
