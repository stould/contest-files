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

const Int INF = 10010010010010010LL;

int T, N;
Int K;
int id;
map<string, int> mp;
vector<pair<int, int> > P[1010];

int gt(string arg) {
    if (mp.find(arg) == mp.end()) {
        mp[arg] = id++;
    }
    return mp[arg];
}

int main(void) {
    cin >> T;

    while (T--) {
        cin >> N >> K;

        id = 1;
        mp.clear();

        for (int i = 0; i <= N; i++) {
            P[i].clear();
        }
        
        for (int i = 0; i < N; i++) {
            string type, name;
            int cst, qlt;
            
            cin >> type >> name >> cst >> qlt;

            P[gt(type)].push_back(make_pair(cst, qlt));
        }

        int ans = 0;
        int l = 0, h = 1000000005;

        while (l <= h) {
            int m = l + (h - l) / 2;

            bool can = true;
            Int buff = K;
            
            for (int i = 1; i < id; i++) {
                Int pr = INF;
                
                for (int j = 0; j < (int) P[i].size(); j++) {
                    if (P[i][j].second >= m) {
                        pr = min(pr, (Int) P[i][j].first);
                    }
                }
                if (pr == INF) {
                    can = false;
                } else {
                    buff -= pr;
                }
            }
            
            if (buff < 0) {
                can = false;
            }
            if (can) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
