1class Solution {
2public:
3    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
4           if(n == 0) return true;
5
6
7        flowerbed.insert(flowerbed.begin(), 0);
8        flowerbed.push_back(0);
9
10        for (int i = 1; i < flowerbed.size() - 1; i++) {
11
12            if (flowerbed[i] == 0 &&
13                flowerbed[i-1] == 0 &&
14                flowerbed[i+1] == 0) {
15
16                flowerbed[i] = 1;
17                n--;
18            }
19
20            if (n == 0)
21                return true;
22        }
23     
24        return false;
25    }
26};