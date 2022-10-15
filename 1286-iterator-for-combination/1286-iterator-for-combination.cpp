class CombinationIterator {
public:
    vector<string> combination;
    int index = 0;
    CombinationIterator(string characters, int combinationLength) {
        int sz = 1 << characters.size();
        for(int i = 0; i < sz; i++) {
            int count = 0;
            int k = 0;
            string s = "";
            for(int j = i; j > 0; j /= 2) {
                if(j % 2) {
                    count += j % 2;
                    s += characters[k];
                }
                k++;
            }
            if(count == combinationLength)
                combination.push_back(s);
        }
        sort(combination.begin(), combination.end());
    }
    
    string next() {
        return combination[index++];
    }
    
    bool hasNext() {
        return index < combination.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */