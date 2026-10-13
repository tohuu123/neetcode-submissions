class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m - 1;
        while (l <= r) { 
            int mid = l + (r - l)/2;
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) { 
                int L = 0, R = n - 1;
                while (L <= R) { 
                    int MID = L + (R - L) / 2;
                    if (matrix[mid][MID] == target)
                        return true;
                    else if (matrix[mid][MID] > target)
                        R = MID - 1;
                    else L = MID + 1;
                }
                // if dont see => return false
                // no searching anymore
                return false;
            }
            else if (matrix[mid][0] > target)
                r = mid - 1;
            else l = mid + 1;
        }  
        return false;
    }
};
