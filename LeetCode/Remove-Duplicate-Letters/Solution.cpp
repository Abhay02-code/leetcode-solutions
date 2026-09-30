1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4
5        vector<int> freq(26, 0);
6
7        // Count characters
8        for(char c : s) {
9            freq[c - 'a']++;
10        }
11
12        stack<char> st;
13        vector<bool> used(26, false);
14
15        for(char c : s) {
16
17            // Current character is processed
18            freq[c - 'a']--;
19
20            // If already in stack, skip
21            if(used[c - 'a']) {
22                continue;
23            }
24
25            // Monotonic stack
26            while(!st.empty() &&
27                  st.top() > c &&
28                  freq[st.top() - 'a'] > 0) {
29
30                used[st.top() - 'a'] = false;
31                st.pop();
32            }
33
34            st.push(c);
35            used[c - 'a'] = true;
36        }
37
38        string ans = "";
39
40        while(!st.empty()) {
41            ans += st.top();
42            st.pop();
43        }
44
45        reverse(ans.begin(), ans.end());
46
47        return ans;
48    }
49};