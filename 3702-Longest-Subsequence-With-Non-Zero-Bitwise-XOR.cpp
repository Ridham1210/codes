class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool n_z = false;
        for(int num : nums){
            if(num) n_z = true;
            xr ^= num;
        }
        if(xr) return n;
        if(n_z) return n-1;
        return 0;
    }
};