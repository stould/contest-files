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

const int MAXN = 200005;

int K, N;
string S;
int tree[30][MAXN];
vector<pair<int, int> > C[30];

void update(int tr, int pos, int v) {
    pos += 1;
    
    for (int i = pos; i < MAXN; i += (i & -i)) {
        tree[tr][i] += v;
    }
}

int get(int tr, int pos) {
    pos += 1;
    
    int ans = 0;

    for (int i = pos; i > 0; i -= (i & -i)) {
        ans += tree[tr][i];
    }
    
    return ans;
}

int main(void) {
    cin >> K >> S >> N;

    int L = (int) S.size();
    
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < K; j++) {
            C[S[i] - 'a'].push_back(make_pair(i + j * L, 1));
        }
    }

    for (int i = 0; i < 26; i++) {
        sort(C[i].begin(), C[i].end());

        for (int j = 0; j < (int) C[i].size(); j++) {
            update(i, j, 1);
        }
    }
    
    for (int i = 0; i < N; i++) {
        int pos;
        char kind;

        cin >> pos >> kind;
        
        int l = 0, h = (int) C[kind - 'a'].size() - 1;
        int goal = -1;
        
        while (l <= h) {
            int m = (l + h) / 2;
            
            int cnt = get(kind - 'a', m);

            if (cnt >= pos) {
                goal = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        assert(goal >= 0);
        //cout << goal << " " << C[kind - 'a'].size() << " " << C[kind - 'a'][goal].first << endl;
        update(kind - 'a', goal, -1);
        C[kind - 'a'][goal].second = 0;        
    }

    vector<pair<int, char> > ans_buff;
    
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < (int) C[i].size(); j++) {
            if (C[i][j].second == 1) {
                ans_buff.push_back(make_pair(C[i][j].first, 'a' + i));
            }
        }
    }

    sort(ans_buff.begin(), ans_buff.end());

    string ans = "";

    for (int i = 0; i < (int) ans_buff.size(); i++) {
        ans += ans_buff[i].second;
    }
    
    cout << ans << endl;

    return 0;
}
