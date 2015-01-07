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

int main(void) {
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main() {
    int N, M, ct = 0;

    cin >> N >> M;
    vector<int> memo(N);

    for(int i = 0; i < N; i++) scanf("%d", &memo[i]);

    sort(memo.begin(), memo.end());

    for(int i = memo.size() - 1; i >= 0 && ct < M; i--, ct++) {
        cout << memo[i] << endl;
    }
    return 0;
}
