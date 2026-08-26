class Solution {
public:
    void beauty(string s, int k, string& ans){
        int n = s.length();
        int left = 0;
        int right = 0;
        int one = 0;
        while(right < n){
            
            if(s[right] == '1') one++;
            
            while(one > k){
                if(s[left] == '1') one--;
                left++;
            }
            if(one == k) {
                //cout << s.substr(left, right-left+1) << endl;
                while(s[left] == '0') left++;
                while(s[left] == '0') right--;
                cout << s.substr(left, right-left+1) << endl;
                if(right-left+1 < ans.length()) ans = s.substr(left, right-left+1);
                else if(ans == "" || (s.substr(left, right-left+1) < ans && right-left+1 <= ans.length()) ) ans = s.substr(left, right-left+1);
                }
            right++;
        }
    }
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        beauty(s, k, ans);
        return ans;
    }
};