class Solution {
   public:
    string minWindow(string s, string t) {
        map<char, int> counT;
        map<char, int> window;
        for (char x : t) counT[x]++;

        // need: number of disinct character in t
        // have = len -> ok
        int need = counT.size(), have = 0;
        int l = 0;
        int cntMin = INT_MAX;
        int L = 0, R = 0;
        for (int r = 0; r < s.size(); r++) {
            window[s[r]]++;
            if (counT[s[r]] == window[s[r]]) have++;
            while (need == have) {
                if (r - l + 1 < cntMin) {
                    cntMin = r - l + 1;
                    L = l; 
                    R = r;
                }
                window[s[l]]--;
                if (counT[s[l]] && counT[s[l]] > window[s[l]]) have--;
                //.counT
                l++;
            }
        }
        return cntMin == INT_MAX ? "" : s.substr(L, R - L + 1);
    }
};

// O(n+m), O(k)
// n: s, m: t
// k: total unique in s and t

// OUZODYXAZV
//