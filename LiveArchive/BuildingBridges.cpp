#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int T, N;
int A[MAXN], B[MAXN];

inline void rd(int &x) {
    register int c = getchar_unlocked();   
    x = 0;
    int neg = 0;

    for (; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if (c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }

    for ( ; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if (neg) {
        x = -x;
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int lis(vector<pair<int, int> > sb) {
    multiset<int> lis;
    multiset<int>::iterator it;
       
    for (int i = 0; i < N; i++) {
        lis.insert(sb[i].second);
        it = lis.upper_bound(sb[i].second);

        if (it != lis.end()) {
            lis.erase(it);
        }
    }
    return (int) lis.size();
}

int main() {
    rd(T);
   
    for ( ; T--; ) {
        rd(N);
       
        vector<pair<int, int> > sb;
   
        for (int i = 0; i < N; i++) {
            rd(A[i]);
        }
        for (int i = 0; i < N; i++) {
            rd(B[i]);
            sb.push_back(make_pair(A[i], B[i]));
        }
       
        sort(sb.begin(), sb.end());
       
        int ans = lis(sb);
   
        printf("%d\n", ans);
    }

    return 0;
}
