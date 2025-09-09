

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        backtrack(res, cur, 0, 0, n);
        return res;
    }
    
private:
    void backtrack(vector<string>& res, string& cur, int open, int close, int n) {
        // If we've used up all pairs, add to results
        if ((int)cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }
        // We can add '(' if we still have some left
        if (open < n) {
            cur.push_back('(');
            backtrack(res, cur, open + 1, close, n);
            cur.pop_back();
        }
        // We can add ')' if it won't lead to invalid sequence
        if (close < open) {
            cur.push_back(')');
            backtrack(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
};