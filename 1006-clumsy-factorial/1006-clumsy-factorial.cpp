class Solution {
public:
    int clumsy(int n) {
        int ans = 0;
        for(int i = n; i >= 1; i -= 4) {
            int temp = i;
            for(int j = 1; j <= 2 && i - j > 0; j++) {
                if(j == 1)
                    temp *= (i - j);
                else
                    temp /= (i - j);
            }
            if(i == n)
                ans = temp;
            else 
                ans -= temp;
            ans = i - 3 > 0? ans + i - 3: ans; 
        }
        return ans;
    }
};