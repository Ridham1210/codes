class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        vector<bool> ispresent(maxi-mini+1, false);
        for(int i=0; i<n; i++){
            ispresent[nums[i] - mini] = true;
        }
        for(int i=0; i<ispresent.size(); i++){
            if(!ispresent[i]) ans.push_back(i + mini);
        }
        return ans;
    }
};