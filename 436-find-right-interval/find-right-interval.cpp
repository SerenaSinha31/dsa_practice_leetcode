#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> startToIndex; // pair of start time and original index

        // Populate startToIndex with start times and their original indices
        for (int i = 0; i < n; ++i) {
            startToIndex.emplace_back(intervals[i][0], i);
        }

        // Sort based on start times
        sort(startToIndex.begin(), startToIndex.end());

        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            int target = intervals[i][1];

            // Binary search to find the minimal start >= target
            int left = 0, right = n - 1;
            int idx = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (startToIndex[mid].first >= target) {
                    idx = startToIndex[mid].second;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            result[i] = idx;
        }
        return result;
    }
};