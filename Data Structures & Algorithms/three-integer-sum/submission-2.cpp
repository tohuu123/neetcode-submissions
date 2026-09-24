class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans; 
        for (int i = 0; i < nums.size(); i++) { 
            int l = i + 1, r = nums.size() - 1;
            // already use => duplicate
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue; 
            while (l < r) { 
               if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
               }
               else if (nums[l] + nums[r] + nums[i] > 0) r--;
               else l++;
            }
            // 
        }
        return ans; 
    }
};

/*
-1, 0, 1, 2, -1, -4
-4 -1 -1 0 1 2

numi + numj = -num[k]
*/ 