class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> cnt;
        int lengthCharMax = 0; 
        int l = 0, ans = 0;
        for (int r = 0; r < s.size(); r++) { 
            cnt[s[r]]++;
            lengthCharMax = max(lengthCharMax, cnt[s[r]]);

            while (r - l + 1 - lengthCharMax > k) { 
                cnt[s[l]]--;
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
