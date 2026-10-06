1class Solution {
2public:
3    int minDistance(string word1, string word2) {
4        int m = word1.size(), n = word2.size();
5        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
6        for(int i = 1; i <= word1.size(); i++){
7            for(int j = 1; j <= word2.size(); j++){
8                if(word1[i-1] == word2[j-1]){
9                    dp[i][j] = 1+dp[i-1][j-1];
10                }
11                else{
12                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
13                }
14            }
15        }
16        int l = dp[m][n];
17        return m+n-2*l;
18        
19    }
20};