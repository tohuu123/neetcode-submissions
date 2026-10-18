class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do { 
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        int entryCycle = 0;
        while (entryCycle != slow) {
            entryCycle = nums[entryCycle];
            slow = nums[slow];
        }
        return entryCycle;
    }
};
// VALUE -> valid index
// Detect cycle 

// 1,2,3,2,2
// 0 --> nums[0]: 1
// 1 --> nums[1]: 2
// 2 --> nums[2]: 3
// 3 --> nums[3]: 2 (already)
// 2 --> nums[2]: 3