class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int n : nums)
            freq[n]++;

        // Step 2: Move (number, frequency) pairs to a vector
        vector<pair<int, int>> arr(freq.begin(), freq.end());

        // Step 3: Sort by frequency in descending order
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // Step 4: Take top k elements
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(arr[i].first);

        return result;
    }
};
