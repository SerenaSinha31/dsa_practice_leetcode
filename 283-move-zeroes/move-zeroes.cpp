class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        // int j = n - 1;
        // while(i<=j){
        //     if(nums[j]==0){
        //         j--;
        //         }
        //     else if(nums[i]>0){
        //         i++;
        //     }
        //     else{
        //        swap(nums[i],nums[j]);
        //        i++;
        //        j--;
              
        //     }

          

        // }
        //move the non zero in front in order
        for(int j = 0; j < n; j++){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
        }
        //fill the remaing pos with 0
        while(i<n){
            nums[i]=0;
            i++;
        }

        
    }
};