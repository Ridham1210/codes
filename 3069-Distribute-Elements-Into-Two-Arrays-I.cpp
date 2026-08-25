class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
            if(v1.back() > v2.back()) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        } 
        int i=0, j=0, k=0;
        while(i < v1.size()) nums[k++] = v1[i++];
        while(j < v2.size()) nums[k++] = v2[j++];
        return nums;
    }
};