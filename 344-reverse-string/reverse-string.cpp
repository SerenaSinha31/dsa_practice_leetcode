class Solution {
public:
    void reverseString(vector<char>& s) {
       int n = s.size();
       int start=0, end=n-1;
       for(int i =0; i < n;i++ ){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;

        }
     
       } 
     
    }
};