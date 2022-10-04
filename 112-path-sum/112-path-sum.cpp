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
class Solution {
public:
    void solve(TreeNode* root, int targetSum, bool &ans) {
        if(ans == true || root == nullptr) return;
        if(root -> left == nullptr && root -> right == nullptr) {
            if(targetSum == root -> val) ans = true;
            return;
        }
        solve(root -> left, targetSum - root -> val, ans);
        solve(root -> right, targetSum - root -> val, ans);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        solve(root, targetSum, ans);
        return ans;
    }
};