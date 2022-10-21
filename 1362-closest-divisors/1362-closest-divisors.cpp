class Solution {
public:
    vector<int> closestDivisors(int num) {
        int A = num + 1;
        int x, y, u, v;
        for(int i = sqrt(A); i >= 1; i--) {
            if(A % i == 0) {
                u = i;
                v = A / i;
                break;
            }
        }
        int B = num + 2;
        for(int i = sqrt(B); i >= 1; i--) {
            if(B % i == 0) {
                x = i;
                y = B / i;
                break;
            }
        }
        if(v - u < y - x) return {u, v};
        return {x, y};
    }
};