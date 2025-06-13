/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
        
//     }
// };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case 1: Both nodes are null, meaning we've reached the end of a branch
        // and they are identical in this part.
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Base Case 2: One node is null while the other is not.
        // This means the trees are not identical at this point.
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Base Case 3: Both nodes are not null, but their values are different.
        // This means the trees are not identical.
        if (p->val != q->val) {
            return false;
        }

        // Recursive Step: If values are the same, check their left subtrees
        // and their right subtrees recursively.
        // Both left and right subtrees must be identical for the current nodes to be
        // considered part of a "same tree".
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};