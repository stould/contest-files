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

typedef long long Int;
typedef unsigned uint;

const int MAXN = 500;

int N, M.
char name[15];

vector<pair<int, int> > graph[MAXN];

int main(void) {
    int i;
    int j;

    for ( ; scanf("%s", name) == 1; ) {
        N = in();
        M = in();

        for (i = 0; i < N; i++) {
            graph[i].push_back(make_pair(i + 1, 2));
        }

        for (i = 0; i < M * (N - 1); i++) {
            for (j = 0; j < M; j++) {

            }
        }

        printf("%s\n", name);
    }
    return 0;
}
