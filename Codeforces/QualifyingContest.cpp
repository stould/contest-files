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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 10010;
int N, M;
vector<pair<int, string> > C[MAXN];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string S;
        int R, P;
        
        cin >> S >> R >> P;

        R -= 1;
        
        C[R].push_back(make_pair(P, S));
    }

    for (int i = 0; i < M; i++) {
        sort(C[i].rbegin(), C[i].rend());

        if (C[i].size() > 2 && C[i][1].first == C[i][2].first) {
            cout << "?\n";
        } else {
            cout << C[i][0].second << " " << C[i][1].second << "\n";
        }
    }
    return 0;
}
