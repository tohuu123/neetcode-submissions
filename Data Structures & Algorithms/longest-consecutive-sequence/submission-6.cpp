class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
        [a b] [b,c] 
        at b update new length
        => at a,c also update the length (boundaries)
        a: mp[nums[i] - mp[nums[i] - 1]] = length
        */
        unordered_map<int, int> m;
        int longest = 0; 
        for (int x: nums) { 
            if (!m[x]) { 
                int length = m[x - 1] + m[x + 1] + 1;
                longest = max(longest, length);
                m[x] = length; 
                m[x - m[x - 1]] = length;
                m[x + m[x + 1]] = length;
            }
        }
        return longest;
    }
};