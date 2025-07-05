class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);
        int last  = lastOccurrence(nums, target);
        return {first, last};
    }

private:
    int firstOccurrence(const vector<int>& nums, int target) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;        // potential answer
                right = mid - 1;    // look further left
            } else if (nums[mid] < target) {
                left = mid + 1;     // discard left half
            } else {
                right = mid - 1;    // discard right half
            }
        }
        return index;
    }

    int lastOccurrence(const vector<int>& nums, int target) {
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        int index = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                index = mid;        // potential answer
                left = mid + 1;     // look further right
            } else if (nums[mid] < target) {
                left = mid + 1;     // discard left half
            } else {
                right = mid - 1;    // discard right half
            }
        }
        return index;
    }
};
