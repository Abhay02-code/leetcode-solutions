1class Solution {
2public:
3    bool sumGame(string num) {
4        int n = num.size();
5
6        int sum = 0;
7        int q = 0;
8
9        for(int i = 0; i < n/2; i++){
10            if(num[i] == '?') q++;
11            else sum += num[i] - '0';
12        }
13        for(int i = n/2; i < n; i++){
14            if(num[i] == '?') q--;
15            else sum -= num[i] - '0';
16        }
17        if(q%2 != 0) return true;
18
19        return sum != -9*q/2;
20        
21    }
22};