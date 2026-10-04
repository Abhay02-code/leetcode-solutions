1class Solution {
2public:
3    int countPairs(vector<int>& nums, int target) {
4        int n = nums.size();
5        int count = 0;
6        for(int i = 0; i < n; i++){
7            for(int j = i+1; j < n; j++){
8                if(nums[i]+nums[j] < target){
9                    count++;
10                }
11
12            }
13        }
14        return count;
15        
16    }
17};