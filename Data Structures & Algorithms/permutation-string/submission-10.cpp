class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        vector<int> cnt1(26);
        vector<int> cnt2(26);   

        for (int i = 0; i < s1.size(); i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }        

        int same = 0;
        for (int i = 0; i < 26; i++) { 
            if (cnt1[i] == cnt2[i]) same++;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) { 
            if (same == 26) return true;

            int index = s2[r] - 'a';
            cnt2[index]++;
            if (cnt1[index] == cnt2[index]) 
                same++;
            else if (cnt1[index] + 1 == cnt2[index])
                same--;
            
            int indexx = s2[l] - 'a';
            cnt2[indexx]--;
            if (cnt1[indexx] == cnt2[indexx])
                same++;
            else if (cnt1[indexx] - 1 == cnt2[indexx])
                same--;

            l++;
        }
        return same == 26;
    }
};

/*
aaa
bbb

a: 3
b: 3

*/
