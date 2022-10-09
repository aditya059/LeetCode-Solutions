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
    void solve(TreeNode* root, int &k, unordered_set<int> &seen, bool &ans) {
        if(ans || !root) return;
        solve(root -> left, k, seen, ans);
        if(seen.find(k - root -> val) != seen.end()) {
            ans = true;
            return;
        }
        seen.insert(root -> val);
        solve(root -> right, k, seen, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        unordered_set<int> seen;
        solve(root, k, seen, ans);
        return ans;
    }
};