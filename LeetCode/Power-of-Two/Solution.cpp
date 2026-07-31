1class Solution {
2public:
3    bool isPowerOfTwo(int n) {
4        if(n <= 0) return false;
5
6        return (n & (n-1)) == 0;
7        
8    }
9};