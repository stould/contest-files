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

int T;
int N, M, P;

struct player {
    string name;
    int t;
    int p, h;

    player(){}

    player(string name, int t, int p, int h): name(name), t(t), p(p), h(h) {}

    bool operator<(const player& pl) const {
        if (t != pl.t) {
            return t < pl.t;
        } else {
            if (p != pl.p) {
                return p > pl.p;
            } else {
                return h > pl.h;
            }
        }
    }
    bool operator>(const player& pl) const {
        if (t != pl.t) {
            return t > pl.t;
        } else {
            if (p != pl.p) {
                return p < pl.p;
            } else {
                return h < pl.h;
            }
        }
    }
};

player PL[40];

void fix(priority_queue<player> &q) {
    vector<player> hp;

    for ( ; !q.empty(); ) {
        player p = q.top();
        p.t += 1;
        hp.push_back(p);
        q.pop();
    }
    int i;
    for (i = 0; i < (int) hp.size(); i++) {
        q.push(hp[i]);
    }
}

int main(void) {
    freopen("i.in", "r", stdin);
    freopen("o.ot", "w", stdout);
    cin >> T;

    int t, x;
    int i;

    for (x = 1; x <= T; x++) {
        cin >> N >> M >> P;

        for (i = 0; i < N; i++) {
            cin >> PL[i].name >> PL[i].p >> PL[i].h;
            PL[i].t = 0;
        }

        priority_queue<player, vector<player>, less<player> > p1, p2;
        priority_queue<player, vector<player>, greater<player> > rev1, rev2;

        sort(PL, PL + N);

        for (i = 0; i < N; i++) {
            if (i % 2 == 0) {
                if (p1.size() < P) {
                    p1.push(PL[i]);
                } else {
                    rev1.push(PL[i]);
                }
            } else {
                if (p2.size() < P) {
                    p2.push(PL[i]);
                } else {
                    rev2.push(PL[i]);
                }
            }
        }

        if (2 * P < N) {
            for (t = 0; t < M; t++) {
                fix(p1);
                fix(p2);

                player in1 = rev1.top(); rev1.pop();
                player out1 = p1.top(); p1.pop();

                p1.push(in1);
                rev1.push(out1);

                player in2 = rev2.top(); rev2.pop();
                player out2 = p2.top(); p2.pop();

                p2.push(in2);
                rev2.push(out2);
            }
        }

        vector<string> curr;

        for ( ; !p1.empty(); ) {
            curr.push_back(p1.top().name);
            p1.pop();
        }

        for ( ; !p2.empty(); ) {
            curr.push_back(p2.top().name);
            p2.pop();
        }

        sort(curr.begin(), curr.end());

        cout << "Case #" << x << ": ";

        for (i = 0; i < (int) curr.size(); i++) {
            cout << curr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
