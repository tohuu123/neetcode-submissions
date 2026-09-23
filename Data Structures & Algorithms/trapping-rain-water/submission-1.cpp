class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size(); 
        int l = 0, r = n - 1;
        int leftMax = height[l], rightMax = height[r];
        while (l < r) { 
            if (leftMax < rightMax) { 
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else { 
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res; 
    }
};

/*
min(h[l], h[r]) - h[i]
*/ 