class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numSet;
        int ans = 0;
    
        vector<int> first; 
        
        for (int i = 0; i < nums.size(); i++) { 
            numSet[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++) 
            if (!numSet[nums[i] - 1]) 
                first.push_back(nums[i]);
        for (int i = 0; i < first.size(); i++) { 
                int j = first[i] + 1;
                while (numSet[j]) j++;
                ans = max(ans, j - first[i]);
        }
        return ans; 
    }
};