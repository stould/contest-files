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

int F1, A, B, C;
int N, M;

int main(void) {
    cin >> F1 >> A >> B >> C >> N >> M;

    map<int, int> mp;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int p;
            
            cin >> p;

            mp[p] += 1;
        }
    }

    vector<pair<int, int> > sp;
    vector<pair<int, int> > dv;

    for (auto& it : mp) {
        sp.push_back(make_pair(it.second, it.first));
    }

    sort(sp.rbegin(), sp.rend());
    
    for (int i = 0; i < (int) mp.size(); i++) {
        dv.push_back(make_pair(F1, i));
        F1 = (A * F1 + B) % C;
        F1 = ((F1 % C) + C) % C;
        F1 += 1;
    }

    sort(dv.rbegin(), dv.rend());

    vector<int> ans(mp.size(), 0);
    
    cout << mp.size() << endl;
    
    for (int i = 0; i < (int) mp.size(); i++) {
        ans[dv[i].second] = sp[i].second;
    }

    for (int i = 0; i < (int) mp.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
    
    return 0;
}
