1class Solution {
2public:
3    int maxJump(vector<int>& stones) {
4        int ans = stones[1]-stones[0];
5
6        for(int i = 2; i < stones.size(); i++){
7            ans = max(ans, stones[i]-stones[i-2]);
8
9        }
10        return ans;
11        
12    }
13};