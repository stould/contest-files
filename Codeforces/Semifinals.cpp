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

const int MAXN = 100005;
int N;

int A[MAXN], B[MAXN];
vector<pair<int, pair<int, int> > > all;

int main(void) {
    N = in();

    for (int i = 0; i < N; i++) {
        A[i] = in();
        B[i] = in();

        all.push_back(make_pair(A[i], make_pair(0, i)));
        all.push_back(make_pair(B[i], make_pair(1, i)));
    }

    string AA(N, '0');
    string BB(N, '0');

    sort(all.begin(), all.end());

    int mid = (N % 2 == 0 ? N / 2 : (N - 1) / 2);

    for (int i = 0; i < mid; i++) {
        AA[i] = BB[i] = '1';
    }

    for (int i = 0; i < N; i++) {
        if (all[i].second.first == 0) {
            AA[all[i].second.second] = '1';
        } else {
            BB[all[i].second.second] = '1';
        }
    }

    cout << AA << "\n" << BB << "\n";

    return 0;
}
