1class Solution {
2public:
3    int triangularSum(vector<int>& nums) {
4        int n = nums.size();
5        while(n>1){
6          vector<int>arr;
7            for(int i = 0; i < n-1; i++){
8               arr.push_back((nums[i]+nums[i+1])%10);
9            }
10            nums = arr;
11            n--;
12        }
13        return nums[0];
14        
15    }
16};