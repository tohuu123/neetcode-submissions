class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longest = 0; 
        for (int x: numSet) { 
            if (numSet.find(x - 1) == numSet.end()) { 
                int length = 1;
                while (numSet.find(x + length) != numSet.end()) { 
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};