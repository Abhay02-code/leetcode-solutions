1class MinStack {
2public:
3    stack<int> st;
4    stack<int> minSt;
5
6    MinStack() {
7        
8    }
9    
10    void push(int val) {
11        st.push(val);
12
13        if(minSt.empty() || val <= minSt.top()) {
14            minSt.push(val);
15        }
16    }
17    
18    void pop() {
19        if(st.top() == minSt.top()) {
20            minSt.pop();
21        }
22
23        st.pop();
24    }
25    
26    int top() {
27        return st.top();
28    }
29    
30    int getMin() {
31        return minSt.top();
32    }
33};