class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return  INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;
        bool sign = (dividend < 0)^(divisor < 0);
        long long div = labs(dividend), dis = labs(divisor);
        long long quotient = 0;
        while(div >= dis){
            long long temp = dis;
            long long mul = 1;
            while(div >= (temp << 1)){
                temp <<= 1;
                mul <<= 1;
            }
            div -= temp;
            quotient += mul;
        }
        long long ans = (sign ? -quotient : quotient);
        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;
        return (int)ans;
    }
};