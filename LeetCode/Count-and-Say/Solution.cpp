1class Solution {
2public:
3    string countAndSay(int n) {
4        string ans = "1";
5
6        for (int i = 2; i <= n; i++) {
7            string temp = "";
8            int count = 1;
9
10            for (int j = 1; j < ans.size(); j++) {
11                if (ans[j] == ans[j - 1]) {
12                    count++;
13                } else {
14                    temp += to_string(count);
15                    temp += ans[j - 1];
16                    count = 1;
17                }
18            }
19
20            
21            temp += to_string(count);
22            temp += ans.back();
23
24            ans = temp;
25        }
26
27        return ans;
28    }
29};