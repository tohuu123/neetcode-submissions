class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size(); 
        stack<int> st;
        for (int i = 0; i < n; i++) { 
            while (!st.empty() && height[st.top()] < height[i]) { 
                int mid = height[st.top()];
                st.pop(); 
                // left wall not include 
                if (!st.empty()) { 
                    int left = height[st.top()];
                    // height and width
                    int h = min(height[i], left) - mid;
                    int w = i - st.top() - 1; 
                    res += h * w;
                }
            }
            st.push(i);
        }
        return res; 
    }
};

/*
min(h[l], h[r]) - h[i]
*/ 