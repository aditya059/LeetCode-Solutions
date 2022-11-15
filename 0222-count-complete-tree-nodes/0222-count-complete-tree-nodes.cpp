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
    int height(TreeNode* root) {
        if(!root) return -1;
        return 1 + height(root -> left);
    }
    int countNodes(TreeNode* root) {
        int treeHeight = height(root);
        if(treeHeight < 0) return 0;
        if(height(root -> right) == treeHeight - 1) 
            return (1 << treeHeight) + countNodes(root -> right);
        return (1 << (treeHeight - 1)) + countNodes(root -> left);
    }
};

/*
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
*/