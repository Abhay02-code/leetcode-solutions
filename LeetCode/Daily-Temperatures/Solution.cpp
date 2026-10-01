1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        
5        vector<int> ans(temperatures.size(), 0);
6        stack<int> st;
7
8        for(int i = 0; i < temperatures.size(); i++) {
9            
10            // what should come here?
11            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
12                ans[st.top()] = i - st.top();
13                st.pop();
14            }
15            st.push(i);
16            
17        }
18
19        return ans;
20    }
21};