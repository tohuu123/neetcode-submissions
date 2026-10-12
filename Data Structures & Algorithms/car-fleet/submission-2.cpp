class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        map<int, int> speedMap;
        for (int i = 0; i < position.size(); i++) speedMap[position[i]] = speed[i];
        sort(position.begin(), position.end());
        for (int i = position.size() - 1; i >= 0; i--) {
            double time = (double) (target - position[i]) / speedMap[position[i]];

            if (!st.empty() && time <= st.top()) { 
                continue;
            }
            st.push(time);
        }
        return st.size(); 
    }
};
