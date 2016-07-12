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

const int MAXN = 20020;
const int INF = INT_MAX / 5;

int T, N;
pair<int, int> P[MAXN];
int tree[MAXN];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int get(int pos) {
    int ans = 0;

    while (pos > 0) {
        ans = max(ans, tree[pos]);
        pos -= pos & -pos;
    }

    return ans;
}

void update(int pos, int new_value) {
    while (pos < MAXN) {
        tree[pos] = max(tree[pos], new_value);
        pos += pos & -pos;
    }
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N;

        memset(tree, 0, sizeof(tree));

        set<int> st;
        map<int, int> mp;
        int pos = 1;

        for (int i = 0; i < N; i++) {
            cin >> P[i].first >> P[i].second;
            st.insert(P[i].second);
        }
        
        sort(P, P + N, cmp);

        for (set<int>::reverse_iterator it = st.rbegin(); it != st.rend(); it++) {
            mp[*it] = pos++;
        }

        for (int i = 0; i < N; i++) {
            P[i].second = mp[P[i].second];
        }

        int ans = 1;

        for (int i = 0; i < N; i++) {
            int now = get(P[i].second);
            update(P[i].second, now + 1);
            ans = max(ans, now + 1);
        }

        cout << ans << endl;
    }
    return 0;
}
