class Solution {
public:
    typedef struct job {
        int start, end, profit;
        job(int start, int end, int profit) {
            this -> start = start;
            this -> end = end;
            this -> profit = profit;
        }
    } job;
    static bool comp(const job &A, const job &B) {
        return A.end < B.end;
    }
    int binary_search(vector<job> &Jobs, int n, int item) {
        int low = 0;
        int high = n;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(item >= Jobs[mid].end) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<job> Jobs; 
        for(int i = 0; i < n; i++) {
            Jobs.push_back(job(startTime[i], endTime[i], profit[i]));
        }
        sort(Jobs.begin(), Jobs.end(), comp);
        vector<int> DP(n);
        DP[0] = Jobs[0].profit;
        for(int i = 1; i < n; i++) {
            int include = Jobs[i].profit;
            int index = binary_search(Jobs, i - 1, Jobs[i].start);
            if(index != -1)
            include += DP[index];
            DP[i] = max(DP[i - 1], include);
        }
        return DP[n - 1];
    }
};