1class Solution {
2public:
3    int numRollsToTarget(int n, int k, int target) {
4        vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
5        int MOD = 1e9 + 7;
6        dp[0][0] = 1;
7        for(int dice = 1; dice <= n; dice++){
8            for(int sum = 1; sum <= target; sum++){
9                for(int face = 1; face <= k; face++){
10                    if(sum-face >= 0){
11                        dp[dice][sum] += dp[dice-1][sum-face];
12                        dp[dice][sum] %= MOD;
13                    }
14              }
15            }
16        }
17        return dp[n][target];
18        
19    }
20};