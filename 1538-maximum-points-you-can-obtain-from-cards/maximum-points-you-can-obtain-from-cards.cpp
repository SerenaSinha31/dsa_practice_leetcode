class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // 1. Sum of all cards
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        // Edge case: we’re allowed to take every card
        if (k == n) return total;

        // 2. Size of the middle block we must *not* take
        int windowSize = n - k;

        // 3. Find the minimum‑sum window of length windowSize
        int windowSum = 0;
        for (int i = 0; i < windowSize; ++i)
            windowSum += cardPoints[i];          // first window

        int minWindow = windowSum;               // current best (smallest) window

        for (int i = windowSize; i < n; ++i) {   // slide the window across the array
            windowSum += cardPoints[i];                // add new right end
            windowSum -= cardPoints[i - windowSize];   // remove old left end
            minWindow = min(minWindow, windowSum);     // keep the smallest window sum seen
        }

        // 4. The answer is total points minus the smallest middle block we left behind
        return total - minWindow;
    }
};