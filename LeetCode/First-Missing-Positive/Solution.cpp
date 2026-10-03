1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5
6        // Put every useful number at its correct index
7        for(int i = 0; i < n; i++) {
8            while(nums[i] >= 1 && nums[i] <= n &&
9                  nums[nums[i] - 1] != nums[i]) {
10                
11                swap(nums[i], nums[nums[i] - 1]);
12            }
13        }
14
15        // Find the first number not at its correct position
16        for(int i = 0; i < n; i++) {
17            if(nums[i] != i + 1) {
18                return i + 1;
19            }
20        }
21
22        return n + 1;
23    }
24};