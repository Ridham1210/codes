class Solution {
public:
    double myPow(double x, int t) {
        double ans = 1;
        long long n = t;
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        while(n > 0){
            if(n %2 != 0){
                ans *= x;
                n--;
            }
            n /= 2;
            x *= x;
        }
        return ans;
    }
};