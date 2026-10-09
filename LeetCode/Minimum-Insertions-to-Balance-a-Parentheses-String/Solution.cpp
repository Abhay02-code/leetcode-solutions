1
2class Solution {
3public:
4    int minInsertions(string s) {
5        int n = s.size();
6        int count = 0;
7        int balance = 0;
8
9        for(int i = 0; i < n; i++) {
10            if(s[i] == '(') {
11                balance++;
12            }
13            else {
14                if(i + 1 < n && s[i + 1] == ')') {
15                    i++;
16                }
17                else {
18                    count++;
19                }
20
21                if(balance > 0) {
22                    balance--;
23                }
24                else {
25                    count++;
26                }
27            }
28        }
29
30        return count + 2 * balance;
31    }
32};