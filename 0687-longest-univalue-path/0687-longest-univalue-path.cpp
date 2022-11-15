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
    int solve(TreeNode* root, int &ans) {
        if(!root) return 0;
        int l = solve(root -> left, ans);
        int r = solve(root -> right, ans);
        int leftlen = 0, rightlen = 0;
        if(root -> left && root -> left -> val == root -> val)
            leftlen += 1 + l; 
        if(root -> right && root -> right -> val == root -> val)
            rightlen += 1 + r; 
        ans = max(ans, leftlen + rightlen);
        return max(leftlen, rightlen);
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};