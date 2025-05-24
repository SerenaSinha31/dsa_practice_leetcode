// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
        
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            bool alreadyAdded = false;

            // Check if arr[i] is already in result
            for (int x : res) {
                if (arr[i] == x) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (alreadyAdded) continue;

            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i])
                    cnt++;
            }

            if (cnt > (n / 3)) {
                res.push_back(arr[i]);
            }

            if (res.size() == 2) {
                if (res[0] > res[1])
                    swap(res[0], res[1]);
                break;
            }
        }

        return res; 
    }
};
