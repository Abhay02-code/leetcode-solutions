1
2class Solution {
3public:
4    string maxSumOfSquares(int num, int sum) {
5        if (sum > 9 * num) return "";
6
7        string ans = "";
8
9        for (int i = 0; i < num; i++) {
10            int digit = min(9, sum);
11            ans += char('0' + digit);
12            sum -= digit;
13        }
14
15        return ans;
16    }
17};
18