class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> freq; 
        multimap<int, int, greater<int>> Map;
        for(int i = 0; i < barcodes.size(); i++) {
            freq[barcodes[i]]++;
        }
        for(auto iter: freq) {
            Map.insert({iter.second, iter.first});
        }
        int i = 0;
        for(auto iter: Map) {
            int count = iter.first;
            while(count--)
                barcodes[i++] = iter.second;
        }
        i = 0;
        vector<int> ans(barcodes.size());
        for(int k = 0; k < ans.size(); k += 2) {
            ans[k] = barcodes[i++];
        }
        for(int k = 1; k < ans.size(); k += 2) {
            ans[k] = barcodes[i++];
        }
        return ans;
    }
};