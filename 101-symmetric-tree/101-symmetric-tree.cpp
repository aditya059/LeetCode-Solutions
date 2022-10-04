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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode*> Stack;
        Stack.push(root -> left);
        Stack.push(root -> right);
        while(!Stack.empty()) {
            TreeNode* r = Stack.top();
            Stack.pop();
            TreeNode* l = Stack.top();
            Stack.pop();
            if(l == nullptr && r == nullptr) continue;
            if(l == nullptr || r == nullptr || l -> val != r -> val) return false;
            Stack.push(l -> left);
            Stack.push(r -> right);
            Stack.push(l -> right);
            Stack.push(r -> left);
        }
        return true;
    }
};

/*
class Solution {
public:
    bool solve(TreeNode* l, TreeNode* r) {
        if(l == nullptr && r == nullptr) return true;
        if(l == nullptr || r == nullptr) return false;
        return (l -> val == r -> val) && solve(l -> left, r -> right) && solve(l -> right, r -> left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return solve(root -> left, root -> right);
    }
};
*/