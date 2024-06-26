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
    void solve(TreeNode* root, int val, int depth) {
        if(!root || depth < 2) return;
        if(depth == 2) {
            TreeNode *l = new TreeNode(val);
            TreeNode *r = new TreeNode(val);
            l -> left = root -> left;
            root -> left = l;
            r -> right = root -> right;
            root -> right = r;
            return;
        }
        addOneRow(root -> left, val, depth - 1);
        addOneRow(root -> right, val, depth - 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *ptr = new TreeNode(val);
            ptr -> left = root;
            return ptr;
        }
        solve(root, val, depth);
        return root;
    }
};
