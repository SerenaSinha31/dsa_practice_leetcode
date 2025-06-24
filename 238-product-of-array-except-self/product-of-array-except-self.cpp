class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Prefix pass
        for (int i = 1; i < n; ++i) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        // Suffix pass (on-the-fly)
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= suffix;
            suffix *= nums[i];
        }

        return output;
    }
};
