class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pre(nums.size(), 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0; i<n; i++) cout << pre[i] << " ";
        int count = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i=0; i<n; i++){
            if( mp.find(pre[i] - goal) != mp.end() ){
                count+=mp[pre[i] - goal];
            }
            mp[pre[i]]++;
        }
        return count;
    }
};