class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor){//if dividend and divisor is equal we return 1.
            return 1;
        }
        bool sign = true; //take sign to handle negative integer.
        if(dividend>=0 && divisor<0){
            sign = false;
        }
        if (dividend<0 && divisor>0){
            sign = false;
        }
        long long ans = 0;
        long long n = abs(dividend);
        long long d = abs(divisor);
        while(n>=d){
            int count = 0;
            while(n>=(d<<(count+1))){
                count+=1;
            }
            ans+=1<<count;
            n = (n-(d<<count));
        }
        if (ans==(1<<31)&& sign){
            return INT_MAX;
        }
        if (ans==(1<<31)&& !sign){
            return INT_MIN;
        }
        if (sign==true){
            return ans;
        }
        if(sign==false){
            return -ans;
        }
        return {};
    }
};