1class MyStack {
2public:
3    queue<int>q;
4    MyStack() {
5        
6    }
7    
8    void push(int x) {
9        q.push(x);
10        int n = q.size();
11        for(int i = 0; i < n-1; i++){
12            q.push(q.front());
13            q.pop();
14        }
15        
16    }
17    
18    int pop() {
19        int x = q.front();
20        q.pop();
21        return x;
22        
23    }
24    
25    int top() {
26        return q.front();
27        
28    }
29    
30    bool empty() {
31        return q.empty();
32    }
33};
34
35/**
36 * Your MyStack object will be instantiated and called as such:
37 * MyStack* obj = new MyStack();
38 * obj->push(x);
39 * int param_2 = obj->pop();
40 * int param_3 = obj->top();
41 * bool param_4 = obj->empty();
42 */