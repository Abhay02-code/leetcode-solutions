class Solution {
public:
    vector<int> solve(string expression, int left, int right){
        vector<int>ans;
        for(int i = left; i <= right; i++){
            char op = expression[i];
            if(op == '-' || op == '+' || op == '*'){
                vector<int> leftAns = solve(expression, left, i-1);
                vector<int> rightAns = solve(expression, i+1, right);

                for(int a : leftAns){
                    for(int b : rightAns){
                        if(op == '+') ans.push_back(a+b);
                        else if(op == '-') ans.push_back(a-b);
                        else ans.push_back(a*b);
                    }
                }

            }
        }
        if(ans.empty()){
            string number = expression.substr(left, right-left+1);
            ans.push_back(stoi(number));
        }
        return ans;

    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size());
        
    }
};