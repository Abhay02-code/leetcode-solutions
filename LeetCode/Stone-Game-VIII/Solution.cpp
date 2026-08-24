1class Solution {
2public:
3    int stoneGameVIII(vector<int>& stones) {
4        int n = stones.size();
5        vector<int>prefix(n);
6        prefix[0] = stones[0];
7
8        for(int i = 1; i < n; i++){
9            prefix[i] = prefix[i-1] + stones[i];
10        }
11        int dp = prefix[n-1];
12        for(int i = n-2; i >= 1; i--){
13            dp = max(dp, prefix[i]-dp);
14        }
15        return dp;
16    }
17};