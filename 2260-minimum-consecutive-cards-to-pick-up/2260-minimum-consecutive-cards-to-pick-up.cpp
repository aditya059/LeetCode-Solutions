class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> Map;
        int ans = INT_MAX;
        for(int i = 0; i < cards.size(); i++) {
            if(Map.find(cards[i]) != Map.end())
                ans = min(ans, i - Map[cards[i]] + 1);
            Map[cards[i]] = i;
        }
        return ans == INT_MAX? -1: ans;
    }
};