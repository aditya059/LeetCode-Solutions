class Solution {
public:
    void solve(vector<int> &mask, int i, int &ans, int temp) {
        if(i >= mask.size()) {
            int count = 0;
            while(temp) {
                count++;
                temp -= (temp & -temp);
            }
            ans = max(ans, count);
            return;
        }
        solve(mask, i + 1, ans, temp);
        if(temp & mask[i]) return;
        solve(mask, i + 1, ans, temp | mask[i]);
    }
    int maxLength(vector<string>& arr) {
        vector<int> mask(arr.size()); 
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr[i].size(); j++) {
                int index = arr[i][j] - 'a';
                if(mask[i] & (1 << index)) {
                    mask[i] = 0;
                    break;
                }
                mask[i] |= 1 << index;
            }
        }
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            solve(mask, i, ans, 0);
        }
        return ans;
    }
};


OR


class Solution {
public:
    int dfs(vector<int> &masks, int i, int temp) {
        if(i == masks.size()) {
            return __builtin_popcount(temp);
        }
        return max(dfs(masks, i + 1, temp), (temp & masks[i])? 0: dfs(masks, i + 1, temp | masks[i]));
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> masks(n);
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(char ch: arr[i]) {
                if(mask & (1 << (ch - 'a'))) {
                    mask = 0;
                    break;
                } 
                mask |= (1 << (ch - 'a'));
            }
            masks[i] = mask;
        }
        return dfs(masks, 0, 0);
    }
};
