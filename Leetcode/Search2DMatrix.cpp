#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;


class Solution {
public:
    int N;
    int M;
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        N = (int) matrix.size();
        M = (int) matrix[0].size();
        
        return search(matrix, target, 0, 0, N - 1, M - 1);
    }
    
    bool in(int l, int r, int m) {
        return m >= l && r >= m;
    }
    
    bool valid_position(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
    
    bool search(vector<vector<int> >& matrix, int target, int ui, int uj, int li, int lj) {
        if (ui == li && uj == lj) {
            return matrix[ui][uj] == target;
        } else {
            int mi = (ui + li) / 2;
            int mj = (uj + lj) / 2;
            
            bool ans = false;
            
            if (!ans && valid_position(ui, uj) && valid_position(mi, mj) && in(matrix[ui][uj], matrix[mi][mj], target)) {
                ans |= search(matrix, target, ui, uj, mi, mj);
            }
            if (!ans && valid_position(ui, mj + 1) && valid_position(mi, lj) && in(matrix[ui][mj + 1], matrix[mi][lj], target)) {
                ans |= search(matrix, target, ui, mj + 1, mi, lj);
            }
            if (!ans && valid_position(mi + 1, uj) && valid_position(li, mj) && in(matrix[mi + 1][uj], matrix[li][mj], target)) {
                ans |= search(matrix, target, mi + 1, uj, li, mj);
            }
            if (!ans && valid_position(mi + 1, mj + 1) && valid_position(li, lj) && in(matrix[mi][mj], matrix[li][lj], target)) {
                ans |= search(matrix, target, mi + 1, mj + 1, li, lj);
            }
            return ans;
        }
    }
};

int main(void) {
    return 0;
}
