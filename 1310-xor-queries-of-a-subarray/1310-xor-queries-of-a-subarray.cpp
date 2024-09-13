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

OR

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXorred(n + 1);
        for(int i = 1; i <= n; i++) {
            prefixXorred[i] = prefixXorred[i - 1] xor arr[i - 1];
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(prefixXorred[queries[i][1] + 1] xor prefixXorred[queries[i][0]]);
        }
        return ans;
    }
};
