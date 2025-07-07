// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
        
//     }
// };
class Solution {
public:
 int firstMissingPositive(vector<int>& nums) {
 int n = nums.size();
 // 1. Placement pass
 for (int i = 0; i < n; ++i) {
 /* While current value is in the range [1, n] **and**
 not already in its correct position, swap it there. */
 while (nums[i] >= 1 && nums[i] <= n) {
 int correctIdx = nums[i] - 1;
 // Already in place? break to avoid infinite loop.
 if (nums[i] == nums[correctIdx]) break;
 swap(nums[i], nums[correctIdx]);
 }
 }
 // 2. Scan pass
 for (int i = 0; i < n; ++i)
 if (nums[i] != i + 1)
 return i + 1;
     return n + 1;
    }
};