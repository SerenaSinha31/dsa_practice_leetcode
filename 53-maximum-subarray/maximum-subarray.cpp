class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i < n; i++ )
        {
            current_sum = current_sum + nums[i];
            ans=max(ans,current_sum);
            if(current_sum<0){
                current_sum = 0;

            }
            
        }
        
        return ans;
        
       
        
    }
};