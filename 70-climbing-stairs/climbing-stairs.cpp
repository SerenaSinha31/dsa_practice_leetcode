class Solution {
public:
    int climbStairs(int n) {
    //     if (n <= 1) return n;

    // int pp = 0, p = 1, cur = 0; 

    // for (int i = 1; i <= n; i++) { 
    //     cur = p + pp;
    //     pp = p;
    //     p = cur;
    // }

    // return cur;
    // }
    // if(n==1)return 1;
    // if(n==2)return 2;
    // return climbStairs(n-1)+climbStairs(n-2);
    // int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

    
};