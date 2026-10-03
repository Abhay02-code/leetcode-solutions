1class Solution {
2public:
3    bool check(string s, int left, int right){
4        while(left<right){
5            if(s[left] != s[right]){
6                return false;
7            }
8            left++;
9            right--;
10        }
11        return true;
12    }
13    bool validPalindrome(string s) {
14        int left = 0;
15        int right = s.size()-1;
16        while(left<right){
17            if(s[left] != s[right]){
18                return check(s, left+1, right)||
19                       check(s, left, right-1);
20            }
21            left++;
22            right--;
23        }
24        return true;
25        
26    }
27};