class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) { 
            while (!st.empty() && temperatures[i] > st.top().first) 
            {
                int index = st.top().second;
                ans[index] = i - index;
                st.pop();
            }
            st.push({temperatures[i], i});
        }   
        while (!st.empty()) { 
            int index = st.top().second;
            ans[index] = 0;
            st.pop();
        }
        return ans;
    }
};

/*
NOTE: 

*/