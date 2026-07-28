class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26, 0);
        int n = s.length();
        for(int i=0; i<n/2; i++){
            v[s[i]-'a']++;
        }
        int idx = 0;
        for(int i=0; i<26; i++){
            while(v[i]-- > 0){
                s[idx++] = (char)(i+'a');
            }
        }
        for(int i=0; i<n/2; ++i){
            s[n-i-1] = s[i]; 
        }
        return s;
    }
};