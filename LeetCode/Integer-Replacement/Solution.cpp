1class Solution {
2public:
3    int integerReplacement(int n) {
4        long long x = n;
5        int count = 0;
6        while(x != 1){
7            if(x%2 == 0){
8                x /= 2;
9            }
10            else{
11                if((x == 3) ||  (x & 2) == 0){
12                    x--;
13                }
14                else{
15                    x++;
16                }
17            }
18            count++;
19        }
20        return count;
21        
22        
23    }
24};