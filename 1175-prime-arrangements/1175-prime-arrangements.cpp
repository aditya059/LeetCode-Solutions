class Solution {
public:
    int numPrimeArrangements(int n) {
        const int MOD = 1e9 + 7;
        int prime = 0;
        for(int i = 2; i <= n; i++) {
            int count = 0;
            for(int j = 1; j <= i; j++) {
                if(i % j == 0)
                    count++;
            }
            if(count == 2)
                prime++;
        }
        long ans = 1;
        for(int i = 1; i <= prime; i++) {
            ans = (ans * i) % MOD;
        }
        for(int i = 1; i <= n - prime; i++) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }
};