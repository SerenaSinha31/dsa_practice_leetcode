class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int num=nums[i];
            int sumdigit=0;
            while(num>0){
                int ls=num%10;
                sumdigit=sumdigit+ls;
                num=num/10;
            }
            if(sumdigit==i){
                return i;
            }
        }
        return -1;
    }
};