
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);
        return {first, last};
    }

    // \U0001f539 Function to find the first (leftmost) occurrence
    int firstOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;
                right = mid - 1; // keep searching on the left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return index;
    }

    // \U0001f539 Function to find the last (rightmost) occurrence
    int lastOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;
                left = mid + 1; // keep searching on the right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return index;
    }
};
