1class Solution {
2public:
3    string shortestPalindrome(string s) {
4        string rev = s;
5        reverse(rev.begin(), rev.end());
6
7        // Create combined string
8        string temp = s + "#" + rev;
9
10        // Build LPS array
11        vector<int> lps(temp.size(), 0);
12
13        int len = 0;
14
15        for(int i = 1; i < temp.size(); ) {
16            if(temp[i] == temp[len]) {
17                len++;
18                lps[i] = len;
19                i++;
20            }
21            else if(len > 0) {
22                len = lps[len - 1];
23            }
24            else {
25                lps[i] = 0;
26                i++;
27            }
28        }
29
30        // Length of longest palindromic prefix
31        int palLen = lps.back();
32
33        // Characters after the palindromic prefix
34        string remaining = s.substr(palLen);
35
36        reverse(remaining.begin(), remaining.end());
37
38        return remaining + s;
39    }
40};