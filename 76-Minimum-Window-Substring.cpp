class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        vector<int> mp(128, 0);
        for(char c : t) mp[c]++;
        int left = 0, right = 0;
        int rem = t.length();
        int start = 0;
        int len = INT_MAX;
        while(right < s.length()){
            if(mp[s[right]] > 0){
                rem--;
            }
            mp[s[right]]--;
            right++;
            while(rem == 0){
                if(right - left < len){
                    len = right - left;
                    start = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0) rem++;
                left++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};