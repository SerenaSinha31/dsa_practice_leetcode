class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;

        int n = triangle.size();
        // Start from the second-to-last row and move upward
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // Choose the smaller of the two adjacent numbers in the row below
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        // The top element now contains the minimum total
        return triangle[0][0];
    }
};