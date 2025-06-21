class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int maxcount = 0, count=0;
        for(int i =0; i< n; i++ ){
            if(nums[i]==1){
                count++;
                  maxcount=max(count,maxcount);
            }
            else{
                count = 0;
            }
          

        }
        return maxcount;
    }
};