class Solution {
public:
    set<vector<int>> s;
    void getCombination(vector<int>& arr,int idx, int tar, vector<vector<int>>& ans, vector<int>& combin){
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }



        combin.push_back(arr[idx]);
        
        getCombination(arr, idx+1, tar-arr[idx], ans, combin);
       
        getCombination(arr, idx, tar-arr[idx], ans, combin);
        
        combin.pop_back();
        getCombination(arr, idx+1, tar, ans, combin);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<int>combin;
        vector<vector<int>>ans;
        getCombination(arr, 0, tar, ans, combin);
       return ans;
    }
     
};