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
pair<int, int> P[MAXN];
int all[MAXN];
map<int, int> cnt;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(void) {
    cin >> N;
    
    int ans = INT_MAX;
    int sum = 0;
    
    set<int> vh;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i].first;
        vh.insert(P[i].first);
        cnt[P[i].first] += 1;
    }
    
    for (int i = 0; i < N; i++) {
        cin >> P[i].second;
        sum += P[i].second;
        all[P[i].first] += P[i].second;
    }

    sort(P, P + N, cmp);

    vector<int> vec_h(vh.begin(), vh.end());
    int bigger = 0, bigger_cnt = 0;
    
    for (int i = (int) vec_h.size() - 1; i >= 0; i--) {
        int curr_cost = sum - all[vec_h[i]];
        ans = min(ans, curr_cost);
        
        int left = cnt[vec_h[i]] - 1;

        if (cnt[vec_h[i]] > 1) {        
            for (int j = 0; j < N; j++) {
                if (left == 0) break;
                if (P[j].first < vec_h[i]) {
                    left -= 1;
                    curr_cost -= P[j].second;
                }
            }
        }
        if (left == 0) {
            ans = min(ans, curr_cost);
        }
            
        bigger += all[vec_h[i]];
        bigger_cnt += cnt[vec_h[i]];
    }

    cout << ans << "\n";
    
    return 0;
}
