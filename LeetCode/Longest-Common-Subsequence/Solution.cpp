1class Solution {
2public:
3    int longestCommonSubsequence(string text1, string text2) {
4        int m = text1.size(), n = text2.size();
5        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
6        for(int i = 1; i <= text1.size(); i++){
7            for(int j = 1; j <= text2.size(); j++){
8                if(text1[i-1] == text2[j-1]){
9                    dp[i][j] = 1+dp[i-1][j-1];
10                }
11                else{
12                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
13                }
14            }
15        }
16        return dp[m][n];
17        
18    }
19};