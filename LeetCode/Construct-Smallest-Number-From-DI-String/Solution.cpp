1class Solution {
2public:
3    string smallestNumber(string pattern) {
4        stack<int> st;
5        string ans = "";
6        int digit = 1;
7
8        for(int i = 0; i < pattern.size(); i++) {
9            st.push(digit++);
10
11            if(pattern[i] == 'I') {
12                while(!st.empty()) {
13                    ans += to_string(st.top());
14                    st.pop();
15                }
16            }
17        }
18
19        st.push(digit);
20
21        while(!st.empty()) {
22            ans += to_string(st.top());
23            st.pop();
24        }
25
26        return ans;
27    }
28};