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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> Queue;
        Queue.push(root);
        bool even = false;
        while(!Queue.empty()) {
            even = !even;
            int n = Queue.size();
            int minimum = INT_MAX, maximum = INT_MIN;
            for(int i = 0; i < n; i++) {
                TreeNode* curr = Queue.front();
                Queue.pop();
                if(even) {
                    if(curr -> val % 2 == 0 || curr -> val <= maximum) return false;
                }
                else {
                    if(curr -> val % 2 == 1 || curr -> val >= minimum) return false;
                }
                maximum = max(maximum, curr -> val);
                minimum = min(minimum, curr -> val);
                if(curr -> left)
                    Queue.push(curr -> left);
                if(curr -> right)
                    Queue.push(curr -> right);
            }
        }
        return true;
    }
};