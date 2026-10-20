
class Solution {
public:
    int solve(vector<int>& arr, int idx, int days,
              vector<vector<int>>& dp) {
        int n = arr.size();

        if (days == 1) {
            int maxi = 0;

            for (int i = idx; i < n; i++) {
                maxi = max(maxi, arr[i]);
            }

            return maxi;
        }

        if (dp[idx][days] != -1) {
            return dp[idx][days];
        }

        int ans = INT_MAX;
        int maxi = 0;

        for (int j = idx; j <= n - days; j++) {
            maxi = max(maxi, arr[j]);

            int rem = solve(arr, j + 1, days - 1, dp);
            int total = maxi + rem;

            ans = min(ans, total);
        }

        return dp[idx][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d) return -1;

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

        return solve(jobDifficulty, 0, d, dp);
    }
};
