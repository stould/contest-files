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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 1000005;

int N, K;
int P[MAXN];
int bit[MAXN];

void add(int pos, int val) {
    for (int i = pos; i < MAXN; i += (i & -i)) {
        bit[i] += val;
    }
}

int sumPrefix(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        ans += bit[i];
    }
    return ans;
}

Int getMedian() {
    int l = 0, h = MAXN - 1;
    int p = (K - 1) / 2;

    while (l <= h) {
        int m = l + (h - l) / 2;
        
        int sum = sumPrefix(m);

        if (sum <= p) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return l + 1;
}

int brute() {
    int ans = 0;
    vector<int> vp;

    for (int i = 0; i < N; i++) {
        vp.push_back(P[i]);
    }

    for (int i = 0; i + K <= N; i++) {
        vector<int> ia;
        for (int j = 0; j < K; j++) {
            ia.push_back(vp[i + j]);            
        }
        sort(ia.begin(), ia.end());
        for (int j = 0; j < K; j++) {
            //cout << ia[j] << " ";
        }
        //cout << " = " << ia[K / 2] << "\n";

        ans = max(ans, ia[K / 2]);
    }
    return ans - 1;
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i] += 1;
    }

    for (int i = 0; i < K - 1; i++) {
        add(P[i], 1);
    }

    int ans = 0;
    
    for (int i = K - 1; i < N; i++) {
        add(P[i], +1);

        if (i >= K) {
            add(P[i - K], -1);
        }
        
        int curr = getMedian() - 2;
        chmax(ans, curr);
    }

    cout << ans << "\n";

    return 0;
}
