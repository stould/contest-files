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

int N;
string S;
int vl[10][10];
map<int, pair<int, int> > mp;

int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

int main(void) {
    cin >> N >> S;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vl[i][j] = 1;
            mp[i * 3 + j + 1] = make_pair(i, j);
        }
    }

    vl[3][1] = 1;
    mp[0] = make_pair(3, 1);
    
    vector<pair<int, int> > buff;

    for (int i = 0; i < N; i++) {
        buff.push_back(mp[S[i] - '0']);
    }

    for (int x = 0; x < 8; x++) {
        bool valid = true;

        for (int i = 0; i < N; i++) {
            int pi = buff[i].first  + dx[x];
            int pj = buff[i].second + dy[x];

            if (pi < 0 || pj < 0) {
                valid = false;
            } else {
                if (vl[pi][pj] == 0) {
                    valid = false;
                }
            }
        }
        if (valid) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;    
}
