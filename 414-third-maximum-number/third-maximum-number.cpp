class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            // Skip if the number is already considered
            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // Return third if it exists, otherwise the largest number
        return third == LONG_MIN ? first : third;
    }
};
