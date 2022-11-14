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
    void dfs(TreeNode* root, int &ans, int minimum, int maximum) {
        if(!root) return;
        minimum = min(minimum, root -> val);
        maximum = max(maximum, root -> val);
        ans = max(ans, max(abs(root -> val - minimum), abs(root -> val - maximum)));
        dfs(root -> left, ans, minimum, maximum);
        dfs(root -> right, ans, minimum, maximum);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, root -> val, root -> val);
        return ans;
    }
    
};