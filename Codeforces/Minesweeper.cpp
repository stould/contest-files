#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

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

const int MAXN = 20;

string status[MAXN];
string posits[MAXN];

int N;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(void) {
    int i, j, k;

    N = in();

    for (i = 0; i < N; i++) {
        cin >> status[i];
    }

    bool over = false;

    for (i = 0; i < N; i++) {
        cin >> posits[i];
        for (j = 0; j < N; j++) {
            if (posits[i][j] == 'x' && status[i][j] == '*') {
                over = true;
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (over && status[i][j] == '*') {
                printf("*");
            } else if (posits[i][j] == 'x') {
                int cnt = 0;

                for (k = 0; k < 8; k++) {
                    int di = i + dx[k];
                    int dj = j + dy[k];

                    if (di >= 0 && dj >= 0 && di < N && dj < N && status[di][dj] == '*') {
                        cnt += 1;
                    }
                }

                printf("%d", cnt);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}
