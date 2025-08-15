class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            bool valid = true;
            for(int j=0; j<n; j++){
                // should not compare to itself
                if((i != j) && (nums[i]==nums[j])){
                   valid=false;
                }
            }
            if(valid==true){
                return nums[i];
            }
        }
        return -1;
      
    }
};
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int result = 0;
//         for(int num : nums){
//             result ^= num; // XOR cancels out duplicates
//         }
//         return result;
//     }
// };