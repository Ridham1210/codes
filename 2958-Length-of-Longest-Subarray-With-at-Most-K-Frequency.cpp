class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int max_len = 0;
        int i=0, j=0;
        while(j<n){
            int num = nums[j];
            mp[num]++;
            while(mp[num] > k){
                mp[nums[i++]]--;
            }
            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};