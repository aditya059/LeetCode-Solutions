class Solution {
public:
    static bool comp(vector<int> &first, vector<int> &second) {
        if(first[0] == second[0]) 
            return first[1] > second[1];
        else 
            return first[0] < second[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> Set;
        for(int i = 0; i < envelopes.size(); i++) {
            int index = lower_bound(Set.begin(), Set.end(), envelopes[i][1]) - Set.begin();
            if(index == Set.size())
                Set.push_back(envelopes[i][1]);
            else
                Set[index] = envelopes[i][1];
        }
        return Set.size();
    }
};