class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        for (int i = 0; i < numbers.size(); i++) {
            int x = numbers[i];
            if (m[target - x]) { 
                return {m[target - x], i + 1};
            }
            m[x] = i + 1; 

        }
        return {};
    }
};
