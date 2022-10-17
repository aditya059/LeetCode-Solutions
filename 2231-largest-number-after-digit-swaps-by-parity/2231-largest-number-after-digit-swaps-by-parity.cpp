class Solution {
public:
    int largestInteger(int num) {
        multiset<int> even;
        multiset<int> odd;
        for(int i = num; i > 0; i /= 10) {
            if((i % 10) % 2)
                odd.insert(i % 10);
            else
                even.insert(i % 10);
        }
        int ans = 0;
        long c = 1;
        for(int i = num; i > 0; i /= 10) {
            if((i % 10) % 2) {
                ans = *odd.begin() * c + ans;
                odd.erase(odd.begin());
            }
            else {
                ans = *even.begin() * c + ans;
                even.erase(even.begin());
            }
            c *= 10;
        }
        return ans;
    }
};