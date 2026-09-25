class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 1, r = 1;
        int ans = 0;
        unordered_map<char, int> m; 
        while (r <= s.size()) { 
            if (m[s[r-1]]) { 
                l = max(l, m[s[r-1]] + 1);
            }
            ans = max(ans, r - l + 1);
            m[s[r-1]] = r;
            r++;
        }
        return ans;
    }
};