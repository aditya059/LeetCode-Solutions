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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> Queue;
        Queue.push(root);
        while(!Queue.empty()) {
            int n = Queue.size();
            vector<int> level;
            for(int i = 0; i < n; i++) {
                TreeNode *curr = Queue.front();
                Queue.pop();
                level.push_back(curr -> val);
                if(curr -> left)
                    Queue.push(curr -> left);
                if(curr -> right)
                    Queue.push(curr -> right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};