class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i] xor arr[i - 1];
        }
        vector<int> ans;
        for(vector<int> query: queries) {
            if(query[0] != 0)
                ans.push_back(arr[query[1]] xor arr[query[0] - 1]);
            else
                ans.push_back(arr[query[1]]);
        }
        return ans;
    }
};