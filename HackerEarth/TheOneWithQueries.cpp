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

string S, Q;
int N, M;
vector<int> pos[30];

int main(void) {
    cin >> S >> M;

    N = (int) S.size();

    for (int i = 0; i < N; i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    for (int x = 0; x < M; x++) {
        cin >> Q;

        int pq = -1;

        for (int i = 0; i < (int) Q.size(); i++) {
            int curr = Q[i] - 'a';

            if (pos[curr].empty()) {
                pq = -1;
                break;
            } else {
                vector<int>::iterator it = upper_bound(pos[curr].begin(), pos[curr].end(), pq);

                if (it == pos[curr].end()) {
                    pq = -1;
                    break;
                } else {
                    pq = *it;
                }
            }
        }

        if (pq == -1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}
