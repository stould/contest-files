#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int N;
int A[MAXN], B[MAXN];
map<int, int> mp;
long long tree[MAXN];

void update(int p) {
    for (int i = p; i < MAXN; i += (i & -i)) {
        tree[i] += 1;
    }
}
long long get(int p) {
    long long ans = 0LL;
    for (int i = p; i > 0; i -= (i & -i)) {
        ans += tree[i];
    }
    return ans;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        mp[B[i]] = i + 1;
    }

    long long inv = 0LL;
  
    for (int i = 0; i < N; i++) {
        long long cnt = get(MAXN - 1) - get(mp[A[i]]);
        inv += cnt;
        update(mp[A[i]]);
    }
    if (inv % 2LL == 0LL) {
        cout << "Possible\n";
    } else {
        cout << "Impossible\n";
    }
    return 0;
}
close
