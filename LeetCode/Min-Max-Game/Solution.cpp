1class Solution {
2public:
3    int minMaxGame(vector<int>& nums) {
4        int n = nums.size();
5      
6        while(n>1){
7           
8            for(int i = 0; i < n/2; i++){
9                if(i % 2 == 0){
10                    nums[i] = min(nums[2*i],nums[2*i+1]);
11                }
12                else{
13                    nums[i] = max(nums[2*i],nums[2*i+1]);
14                }
15            }
16            n /= 2;
17        }
18        return nums[0];
19
20        
21    }
22};