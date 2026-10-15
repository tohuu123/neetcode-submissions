class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int MaxValue = *max_element(piles.begin(), piles.end());
        int l = 1, r = MaxValue, res = MaxValue;
        while (l <= r) {
            int mid = l + (r - l)/ 2; 
            int cnt = 0;
            for (int x: piles) { 
                if (mid >= x)
                    cnt++;
                else
                    cnt += (x-1) / mid + 1;
            }
            if (cnt <= h) { 
                res = min(res, mid);
                r = mid - 1;
            }
            else 
                l = mid + 1;
        } 
        return res; 
    }
};


// k = Max
// 0 -> Max2