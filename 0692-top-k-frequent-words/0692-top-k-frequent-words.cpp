class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> Map;
        for(int i = 0; i < words.size(); i++) {
            Map[words[i]]++;
        }
        auto comp = [&](const pair<int, string> &A, const pair<int, string> &B) {
            if(A.first > B.first) return true;
            if(A.first == B.first) return A < B;
            return false;
        };
        set<pair<int, string>, decltype(comp)> pq(comp);
        for(auto iter: Map) {
            pq.insert({iter.second, iter.first});
            if(pq.size() > k)
                pq.erase(--pq.end());
        }
        vector<string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(pq.begin() -> second);
            pq.erase(pq.begin());
        }
        return ans;
    }
};