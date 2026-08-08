1class Solution {
2public:
3    string multiply(string num1, string num2) {
4
5        if (num1 == "0" || num2 == "0")
6            return "0";
7
8        int n = num1.size();
9        int m = num2.size();
10
11        vector<int> result(n + m, 0);
12
13        for (int i = n - 1; i >= 0; i--) {
14
15            for (int j = m - 1; j >= 0; j--) {
16
17                int a = num1[i] - '0';
18                int b = num2[j] - '0';
19
20                int product = a * b;
21
22                int p1 = i + j;
23                int p2 = i + j + 1;
24
25                int sum = product + result[p2];
26
27                result[p2] = sum % 10;
28                result[p1] += sum / 10;
29            }
30        }
31
32        string ans;
33
34        int i = 0;
35
36        // Remove leading zeros
37        while (i < result.size() && result[i] == 0)
38            i++;
39
40        while (i < result.size()) {
41            ans += char(result[i] + '0');
42            i++;
43        }
44
45        return ans;
46    }
47};