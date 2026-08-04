1class Solution {
2public:
3    int tribonacci(int n) {
4        
5        if(n == 0) return 0;
6        if(n == 1 || n == 2) return 1;
7
8        int prev3 = 0;
9        int prev2 = 1;
10        int prev1 = 1;
11
12
13        for(int i = 3; i <= n; i++){
14            int curr = prev3+prev2+prev1;
15            prev3 = prev2;
16            prev2 = prev1;
17            prev1 = curr;
18        }
19        return prev1;
20    }
21};