class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>prefixsumCount(nums.size()+1, 0);
        prefixsumCount[0] = 1;
        int result=0, currSum=0;

        for(int val:nums) {
            currSum+=val;

            if(currSum-goal>=0) result+=prefixsumCount[currSum - goal];

            prefixsumCount[currSum]++;
        }
        return result;
    }
};