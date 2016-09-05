#include <bits/stdc++.h>

using namespace std;

const int MAXN = 330;
const int MAXT = 10005;

int T;
int N;
int df;
int ans;
int key[4][3] = {{1, 2, 3},
                 {4, 5, 6},
                 {7, 8, 9},
                 {-1,0,-1}};

void func(int i, int j, int arg) {
    if (j >= 3 || i >= 4) {        
        if (df > abs(arg - N)) {
            df = abs(arg - N);
            ans = arg;
        }
    } else if (key[i][j] == -1) {
        return func(i + 1, j, arg);
    } else {
        func(i + 1, j, arg);
        func(i + 1, j, arg * 10 + key[i][j]);
        func(i + 1, j, (arg * 10 + key[i][j]) * 10 + key[i][j]);
        func(i + 1, j, ((arg * 10 + key[i][j]) * 10 + key[i][j]) * 10 + key[i][j]);
        func(i, j + 1, arg);
        func(i, j + 1, arg * 10 + key[i][j]);
        func(i, j + 1, (arg * 10 + key[i][j]) * 10 + key[i][j]);
        func(i, j + 1, ((arg * 10 + key[i][j]) * 10 + key[i][j]) * 10 + key[i][j]);
    }
}
int main() {
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        
        df = 100000;
        ans = 0;
        func(0, 0, 0);
        
        cout << ans << "\n";
    }
    return 0;
}
