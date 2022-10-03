class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        vector<pair<int, int>> temp; 
        for(int num: hand) {
            if(temp.empty() || temp.back().first != num)
                temp.push_back({num, 1});
            else
                temp.back().second++;
        }
        for(auto i = 0; i + groupSize <= temp.size(); i++) {
            if(!temp[i].second) continue;
            for(auto j = 1; j < groupSize; j++) {
                temp[i + j].second -= temp[i].second;
                if(temp[i + j].second < 0 || temp[i + j].first - temp[i].first != j) return false;
            }
            temp[i].second = 0;
        }
        for(pair<int, int> iter: temp) {
            if(iter.second) return false;
        }
        return true;
    }
};