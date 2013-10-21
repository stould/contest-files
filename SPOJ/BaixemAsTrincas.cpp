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

int N;
int A[15], B[15];

struct triplet {
    int a, b, c;

    triplet(){}

    triplet(int a, int b, int c): a(a), b(b), c(c){}
};

pair<int, int> func(vector<int > v) {
    int i;

    for (i = 0; i < (int) v.size(); i++) {
        if (v[i] < 0) return make_pair(-1, -1);
    }


}

int main(void) {
    int i, j, k;

    vector<triplet> vt;

    for (i = 1; i <= 13; i++) vt.push_back(triplet(i, i, i));

    for (i = 1; i <= 13; i++) {
        for (j = i; j <= 13; j++) {
            for (k = j; k <= 13; k++) {
                if (i + j > k) {
                    vt.push_back(triplet(i, j, k));
                }
            }
        }
    }

    for ( ; scanf("%d", &N) == 1 && N != 0; ) {
        for (i = 0; i < 15; i++) A[i] = B[i] = 0;

        for (i = 0; i < N; i++) {
            int x = in();
            if (i % 2 == 0) {
                A[x] += 1;
            } else {
                B[x] += 1;
            }
        }

        pair<int, int> a = func(vector<int>(A, A + 13));
/*
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

        for (i = 0; i < vt.size(); i++) {
            while (1) {
                A[vt[i].a] -= 1;
                A[vt[i].b] -= 1;
                A[vt[i].c] -= 1;

                if (A[vt[i].a] >= 0 && A[vt[i].b] >= 0 && A[vt[i].c] >= 0) {
                    if (vt[i].a == vt[i].b && vt[i].a == vt[i].c && vt[i].c == vt[i].c) {
                        a1 += 1;
                    } else {
                        a2 += 1;
                    }
                } else {
                    A[vt[i].a] += 1;
                    A[vt[i].b] += 1;
                    A[vt[i].c] += 1;
                    break;
                }
            }
            while (1) {
                B[vt[i].a] -= 1;
                B[vt[i].b] -= 1;
                B[vt[i].c] -= 1;

                if (B[vt[i].a] >= 0 && B[vt[i].b] >= 0 && B[vt[i].c] >= 0) {
                    if (vt[i].a == vt[i].b && vt[i].a == vt[i].c && vt[i].c == vt[i].c) {
                        b1 += 1;
                    } else {
                        b2 += 1;
                    }
                } else {
                    B[vt[i].a] += 1;
                    B[vt[i].b] += 1;
                    B[vt[i].c] += 1;
                    break;
                }
            }
        }
    */

        if (a1 + a2 > b1 + b2 || (a1 + a2 == b1 + b2 && a1 > b1)) {
            printf("1\n");
        } else if (a1 + a2 < b1 + b2 || (a1 + a2 == b1 + b2 && a1 < b1)) {
            printf("2\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
