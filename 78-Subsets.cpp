class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int poss_ss = 1<<n;
        for(int i=0; i<poss_ss; i++){
            vector<int> v;
            for(int j=0; j<n; j++){
                if(i & (1<<j)) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};