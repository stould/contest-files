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

const int MAXN = 510;
const Int INF = 1001001010010010LL;

int N, K;
Int C[MAXN];
Int dp[MAXN][MAXN];
bool memo[MAXN][MAXN];
string ans_s;

Int func(int pos, int used) {
    if (used > K) return -INF;
    if (pos >= N) {
        return used == K ? 0 : -INF;
    } else {
        Int& ans = dp[pos][used];

        if (memo[pos][used] == false) {
            memo[pos][used] = true;

            ans = func(N, used);
            ans = max(ans, C[pos] + func(pos + 1, used + 1));
            
            if (used == 0) {
                chmax(ans, func(pos + 1, used));
            }
            
            for (int i = pos + 2; i < N; i++) {
                Int off = abs(C[pos] - C[i]) * (Int) (i - pos - 1);

                chmax(ans, C[pos] + C[i] - off + func(i + 1, used + 2));
            }
        }

        return ans;
    }
}

void rec(int pos, int used, string curr) {
    if (ans_s != "" && curr > ans_s) return;
    if (used > K) return;
    if (pos >= N) {
        if (used == K) {
            if (ans_s == "") {
                ans_s = curr;
            } else {
                ans_s = min(ans_s, curr);
            }
        }
        return;
    } else {
        Int useA = C[pos] + func(pos + 1, used + 1);
        
        Int notUsed = -INF;
        Int bestSkip = -INF;
        
        Int skipAll = func(N, used);
        
        if (used == 0) {
            notUsed = func(pos + 1, used);
        }

        vector<string> best;
        
        for (int i = pos + 2; i < N; i++) {
            Int off = abs(C[pos] - C[i]) * (Int) (i - pos - 1);
            
            Int now = C[pos] + C[i] - off + func(i + 1, used + 2);

            if (now > bestSkip) {
                best.clear();
                bestSkip = now;
                best.push_back(to_string(i));
            } else if (now == bestSkip) {
                best.push_back(to_string(i));
            }
        }

        if (skipAll > max(notUsed, max(bestSkip, useA))) {
            rec(N, used, curr);
        }
        if (useA > max(notUsed, max(skipAll, bestSkip))) {
            rec(pos + 1, used + 1, curr + " " + to_string(pos + 1));
        }
        if (notUsed > max(useA, max(skipAll, bestSkip))) {
            rec(pos + 1, used, curr);
        }
        if (bestSkip >= max(useA, max(skipAll, notUsed))) {
            sort(best.begin(), best.end());            
            rec(stoi(best[0]) + 1, used + 2, curr + " " + to_string(pos + 1) + " " + to_string(stoi(best[0]) + 1));            
        }
    }
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    cout << func(0, 0) << endl;
    
    rec(0, 0, "");

    while(ans_s.front() == ' ') {
        ans_s = ans_s.substr(1, ans_s.size());
    }
    
    while (ans_s.back() == ' ') {
        ans_s = ans_s.substr(0, ans_s.size() - 1);
    }
    
    cout << ans_s << endl;
    
    return 0;
}
