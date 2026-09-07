1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int ans = INT_MAX;
5        
6        for(int i = 0; i < nums.size(); i++){
7            if(nums[i] == target){
8               int sum= abs(i-start);
9                ans = min(ans, sum);
10                
11
12            }
13            
14
15        }
16        return ans;
17        
18    }
19};