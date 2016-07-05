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

const int INF = INT_MAX / 4;

int N, B;
pair<int, int> P[100005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    double valA = a.second == 0 ? INF : a.first / (double) a.second;
    double valB = b.second == 0 ? INF : b.first / (double) b.second;

    return valA < valB;
}

int main(void) {
    cin >> N >> B;

    //value
    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
    }
    //price
    for (int i = 0; i < N; i++) {        
        cin >> P[i].second;
    }

    sort(P, P + N, cmp);

    int ans = 0;
    
    for (int i = N - 1; i >= 0; i--) {
        if (P[i].second <= B) {
            ans += P[i].first;
            B -= P[i].second;
        } else {
            ans += floor((B * P[i].first) / (double) P[i].second);
            B = 0;
        }
        //cout << P[i].first << " " << P[i].second << " " << ans <<  " "<< B << "\n";
    }

    int sb = 0;
    for (int i = 1; ; i++) {
        //cout << i << " " << i * (i + 1) / 2 << "\n";
        if (i * (i + 1) / 2 > ans) {
            break;
        }
        sb = i;
    }
    cout << sb << "\n";
    return 0;
}
