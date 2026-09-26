class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> cnt1; 
        for (char x: s1)
            cnt1[x]++;

        map<char,int> cnt2; 
        int l = 0, r = 0; 
        while (r < s2.size()) { 
            cnt2[s2[r]]++;
            if (r - l + 1 == s1.size()) { 
                int same = 0; 
                // duyet toan phan tu cnt1
                for (auto &[ch, count]: cnt1) { 
                    if (count == cnt2[ch])
                        same++;
                } 
                if (same == cnt1.size()) return true; 

                cnt2[s2[l]]--;
                l++;
            }
            r++;
        }
        return false;
    }
};
