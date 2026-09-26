class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> cnt1; 
        for (char x: s1)
            cnt1[x]++;
        for (int l = 0; l <= s2.size() - s1.size() + 1; l++) { 
            map<char,int> cnt2; 
            for (int r = l; r <= l+s1.size() - 1; r++)
                cnt2[s2[r]]++;
            int cntt = s1.size();
            for (char x: s1)
                if (cnt1[x] == cnt2[x]) {
                    cntt--;
                }
            if (cntt == 0) return true;
            cnt2[s2[l]]--;
        }
        return false;
    }
};
