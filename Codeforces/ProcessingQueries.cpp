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

const int MAXN = 200020;

int N, B;
Int T[MAXN], D[MAXN];
Int ans[MAXN];

int main(void) {
    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> T[i] >> D[i];
    }

    Int ct = T[0], max_reached = 0;    
    set<int> q;
    
    q.insert(0);
    
    while (!q.empty()) {
        int curr = *q.begin();
        q.erase(q.begin());
        
        ans[curr] = ct + D[curr];
        
        for (int j = max_reached + 1; j < N; j++) {
            if (T[j] > ans[curr] || (T[j] == ans[curr] && (int) q.size() == B)) {
                break;
            }            
            if (ans[j] != -1 && (int) q.size() < B) {
                q.insert(j);
            } else {
                ans[j] = -1;
            }
            max_reached = j;
        }
        ct = ans[curr];
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";


    return 0;
}
