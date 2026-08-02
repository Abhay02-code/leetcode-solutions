1class Solution {
2public:
3    int addDigits(int num) {
4
5        while (num >= 10) {
6            int sum = 0;
7
8            while (num > 0) {
9                sum += num % 10;
10                num /= 10;
11            }
12
13            num = sum;
14        }
15
16        return num;
17    }
18};