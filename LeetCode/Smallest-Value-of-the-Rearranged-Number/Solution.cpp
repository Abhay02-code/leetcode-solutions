1class Solution {
2public:
3    long long smallestNumber(long long num) {
4        vector<long long>digit;
5        long long n = num;
6        if(n < 0) {
7            n = -n;
8        }
9        while(n > 0){
10             digit.push_back(n%10);
11            n/= 10;
12        }
13        if(num == 0) return 0;
14        if(num > 0){
15            sort(digit.begin(),digit.end());
16            int i = 0;
17            while(digit[i] == 0){
18                i++;
19            }
20            swap(digit[0],digit[i]);
21
22        }else{
23            sort(digit.rbegin(),digit.rend());
24        }
25        long long ans = 0;
26        for(int x : digit){
27            ans = ans * 10 +x;
28        }
29        if(num<0){
30            ans = -ans;
31        }
32        return ans;
33    }
34};