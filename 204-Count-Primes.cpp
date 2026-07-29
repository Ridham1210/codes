class Solution {
public:
    bool isprime(int a){
        for(int i=2; i*i<=a; i++){
            if(a%i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if(n <= 1) return 0;
        int count = 0;
        vector<int> isprime(n+1,1);
        for(int i=2; i<n; i++){
            if(isprime[i]){
                count++;
                for(long long f = i*1ll*i; f<n; f+=i){
                    isprime[f] = 0;
                }
            }
        }
        return count;
    }
};