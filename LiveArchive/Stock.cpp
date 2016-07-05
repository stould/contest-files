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

const int MAXN = 1000005;

int T, N;
Int P[MAXN];
Int sum[MAXN];

int main(void) {
    cin >> T;
    
    while (T--) {
        cin >> N;

        priority_queue<pair<int, int> > q;

        for (int i = 1; i <= N; i++) {
            cin >> P[i];

            sum[i] = P[i];

            sum[i] += sum[i - 1];        
            q.push(make_pair(P[i], i));            
        }

        int last = 1;
        Int ans = 0;
        while (last < N) {
            int pos = q.top().second;
            q.pop();

            //cout << last << " " << pos <<" \n";
            
            if (pos <= last) {
                last = max(last, pos + 1);
                continue;
            }
            
            Int profit = P[pos] * (pos - last);
            
            if (profit > 0) {
                profit -= (sum[pos - 1] - sum[last - 1]);
                if (profit < 0) {
                    break;
                }
                ans += profit;
            }            
            last = pos + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
