1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4        vector<int>ans;
5        stack<int>st;
6        for(int i = 0; i < seq.size(); i++){
7            if(seq[i] == '('){
8                st.push(i);
9                ans.push_back(st.size()%2);
10            }
11            else{
12                ans.push_back(st.size()%2);
13                st.pop();
14            }
15        }
16        return ans;
17        
18    }
19};