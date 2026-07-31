class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0, length = 1, max_length = 0;
        int zeroes = 0;
        while(j < nums.size()){
            if(nums[j] == 0) zeroes++;
            while(zeroes > k){
                if(nums[i] == 0) zeroes--;
                i++;
            }
            length = j-i+1;
            max_length = max(max_length, length);
            j++;
        }
        return max_length;
    }
};