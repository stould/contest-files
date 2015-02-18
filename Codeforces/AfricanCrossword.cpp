#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

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

typedef long long Int;
typedef unsigned uint;

const int MAXN = 110;

int N, M;

string grid[MAXN];

int row[MAXN][30];
int col[MAXN][30];

int main(void) {
    cin >> N >> M;

    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    for (int i = 0; i < N; i++) {
        cin >> grid[i];

        for (int j = 0; j < M; j++) {
            row[i][grid[i][j]] += 1;
            col[j][grid[i][j]] += 1;
        }
    }

    string ans = "";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (row[i][grid[i][j]] == 1 && col[j][grid[i][j]] == 1) {
                ans += grid[i][j];
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
