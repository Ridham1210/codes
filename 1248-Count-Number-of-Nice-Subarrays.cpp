class Solution {
public:
    int Count(vector<int>& nums, int k){
        int i=0, j=0;
        int count = 0, odd = 0;
        while(j < nums.size()){
            if(nums[j] %2 != 0) odd++;
            while(odd > k){
                if(nums[i++] %2 != 0) odd--;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (Count(nums, k) - Count(nums, k-1));
    }
};