class Solution {
public:
    int Count(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> mp;
        int i=0, j = 0;
        int count = 0;
        int arr = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size() == k) arr++;
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (Count(nums,k) - Count(nums,k-1));
    }
};