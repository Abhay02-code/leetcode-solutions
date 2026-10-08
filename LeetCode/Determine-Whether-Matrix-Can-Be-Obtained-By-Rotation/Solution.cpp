1class Solution {
2public:
3    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
4        int n = mat.size();
5       
6        for(int k = 0; k < 4; k++){
7            bool same = true;
8            for(int i = 0; i < n; i++){
9                for(int j = 0; j < n; j++){
10                    if(mat[i][j] != target[i][j]){
11                        same = false;
12                    }
13                }
14            }
15            if(same) return true;
16
17            for(int i = 0; i < n; i++){
18                for(int j = i+1; j < n; j++){
19                    swap(mat[i][j],mat[j][i]);
20                }
21            }
22            for(int i = 0; i < n; i++){
23                reverse(mat[i].begin(),mat[i].end());
24            }
25
26        }
27        return false;
28        
29    }
30};