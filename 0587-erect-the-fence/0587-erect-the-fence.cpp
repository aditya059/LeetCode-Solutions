class Solution {
public:
    int cross_product(vector<int> &O, vector<int> &A, vector<int> &B) {
        return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
    }
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end(), [&](vector<int> A, vector<int> B) {return A[0] < B[0] || (A[0] == B[0] && A[1] < B[1]);});
        vector<vector<int>> Stack;
        for(int i = 0; i < trees.size(); i++) {
            while(Stack.size() >= 2 && cross_product(Stack[Stack.size() - 2], Stack[Stack.size() - 1], trees[i]) < 0)
                Stack.pop_back();
            Stack.push_back(trees[i]);
        }
        for(int i = trees.size() - 1; i >= 0; i--) {
            while(Stack.size() >= 2 && cross_product(Stack[Stack.size() - 2], Stack[Stack.size() - 1], trees[i]) < 0)
                Stack.pop_back();
            Stack.push_back(trees[i]);
        }
        set<vector<int>> Set(Stack.begin(), Stack.end());
        return vector<vector<int>>(Set.begin(), Set.end());                                                           
    }
};