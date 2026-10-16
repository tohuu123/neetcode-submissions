class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, ans = INT_MAX;
        while (l <= r) { 
            int mid = l + (r-l)/2;
            ans = min(ans, nums[mid]);
            // if (nums[l] <= nums[r]) continue;
            if (nums[mid] > nums[r]) 
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return ans;
    }
};

/*
3 4 5 6 | 1 2

a_l <= a_r

a_mid > a_r, l = mid + 1;
a_mid <= a_r , r = mid - 1;
a_mid 
*/