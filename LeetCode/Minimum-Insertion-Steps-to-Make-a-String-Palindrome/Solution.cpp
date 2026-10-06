1class Solution {
2public:
3    int minInsertions(string s) {
4        int n = s.size();
5        vector<int>dp(n+1, 0);
6        for(int i = 1; i <= n; i++){
7            int prev = 0;
8            for(int j = 1; j <= n; j++){
9                int temp = dp[j];
10                if(s[i-1] == s[n-j]){
11                    dp[j] = 1+prev;
12                }
13                else{
14                    dp[j] = max(dp[j],dp[j-1]);
15                }
16                prev = temp;
17
18            }
19        }
20        int lps = dp[n];
21        return n-lps;
22        
23    }
24};