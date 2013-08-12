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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

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

const int MAXN = 60;

int N, M, A, B, C;
int matrix[MAXN][MAXN], V[MAXN], H[MAXN], buffH[MAXN], buffV[MAXN];

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    N = in(), M = in();

    int i, j, k, x;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = in();

            H[i] += matrix[i][j];
            V[j] += matrix[i][j];

            buffV[j] = 0;
        }
        buffH[i] = 0;
    }

    for (i = 0; i < N; i++) {
        buffH[i] += H[i];
        if (i > 0) buffH[i] += buffH[i-1];
    }
    for (i = 0; i < M; i++) {
        buffV[i] += V[i];
        if (i > 0) buffV[i] += buffV[i-1];
    }

    int sons[3] = {0};

    sons[0] = in(), sons[1] = in(), sons[2] = in();

    sort (sons, sons + 3);

    int ways = 0;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N - 1; j++) {
            int buff[3] = {buffH[i], buffH[j] - buffH[i], buffH[N-1] - buffH[j]};

            sort (buff, buff + 3);

            if (sons[0] == buff[0] && sons[1] == buff[1] && sons[2] == buff[2]) {
                ways += 1;
            }
        }
    }


    for (i = 0; i < M; i++) {
        for (j = i + 1; j < M - 1; j++) {
            int buff[3] = {buffV[i], buffV[j] - buffV[i], buffV[M-1] - buffV[j]};

            sort (buff, buff + 3);

            if (sons[0] == buff[0] && sons[1] == buff[1] && sons[2] == buff[2]) {
                ways += 1;
            }
        }
    }

    printf("%d\n", ways);

    return 0;
}
