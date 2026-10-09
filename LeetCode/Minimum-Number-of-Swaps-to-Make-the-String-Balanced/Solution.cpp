1class Solution {
2public:
3    int minSwaps(string s) {
4        int balance = 0;
5        int maxImbalance = 0;
6
7        for(int i = 0; i < s.size(); i++) {
8            if(s[i] == '[') {
9                balance++;
10            }
11            else {
12                balance--;
13            }
14
15            if(balance < 0) {
16                maxImbalance++;
17                balance = 0;
18            }
19        }
20
21        return (maxImbalance + 1) / 2;
22    }
23};