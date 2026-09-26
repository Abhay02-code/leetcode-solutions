1class NeighborSum {
2public:
3    vector<vector<int>> grid;
4    int n;
5    NeighborSum(vector<vector<int>>& grid) {
6        this->grid = grid;
7        this->n = grid.size();
8        
9        
10    }
11    
12    int adjacentSum(int value) {
13        int r, c;
14        for(int i = 0; i < n; i++){
15            for(int j = 0; j < n; j++){
16                if(grid[i][j] == value){
17                    r = i;
18                    c = j;
19
20                }
21            }
22        }
23        int sum = 0;
24        if(r-1>=0){
25            sum += grid[r-1][c];
26        }
27        if(r+1<n) sum+= grid[r+1][c];
28        if(c-1>=0) sum += grid[r][c-1];
29        if(c+1<n) sum += grid[r][c+1];
30        return sum;
31
32        
33    }
34    
35    int diagonalSum(int value) {
36        int r, c;
37        for(int i = 0; i < n; i++){
38            for(int j = 0; j < n; j++){
39                if(grid[i][j] == value){
40                    r = i;
41                    c = j;
42                }
43            }
44        }
45        int sum = 0;
46        if(r-1 >= 0 && c-1 >= 0) sum += grid[r-1][c-1];
47        if(r-1 >= 0 && c+1 < n) sum += grid[r-1][c+1];
48        if(r+1 < n && c+1 < n) sum += grid[r+1][c+1];
49        if(r+1 < n && c-1 >= 0) sum += grid[r+1][c-1];
50        return sum;
51
52        
53    }
54};
55
56/**
57 * Your NeighborSum object will be instantiated and called as such:
58 * NeighborSum* obj = new NeighborSum(grid);
59 * int param_1 = obj->adjacentSum(value);
60 * int param_2 = obj->diagonalSum(value);
61 */