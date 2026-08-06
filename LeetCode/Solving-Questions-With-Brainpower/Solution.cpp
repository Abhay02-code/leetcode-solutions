1class Solution {
2public:
3    long long mostPoints(vector<vector<int>>& questions) {
4
5        int n = questions.size();
6
7        vector<long long> dp(n + 1, 0);
8
9        for(int i = n - 1; i >= 0; i--){
10
11            long long take = questions[i][0];
12
13            int next = i + questions[i][1] + 1;
14
15            if(next < n)
16                take += dp[next];
17
18            long long skip = dp[i + 1];
19
20            dp[i] = max(take, skip);
21        }
22
23        return dp[0];
24    }
25};