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

const int MAXN = 100005;

int N;
int point = 0;
Int A[MAXN], B[MAXN];
Int tree[MAXN];
Int ans[MAXN];
int mapper[MAXN][2];
unordered_map<int, int> parent;
set<int> seen;

int get_parent(int x) {
    //cout << "PARENT\n";

    //cout << "\n";
    //cout << x << " " << *seen.lower_bound(x + 1) << "\n";
    //cout << "DONE\n";
    set<int>::iterator it = seen.lower_bound(x);
    if (it != seen.begin()) {
        it--;
    }
    //cout << x << " => " << *it << "\n";
    return parent[*it];
}

int getnode() {    
    return point++;
}

int main(void) {
    cin.tie(0);    
    ios_base::sync_with_stdio(false);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        tree[i] = -1;
        mapper[i][0] = mapper[i][1] = -1;
        cin >> A[i];
    }

    int pos = 0;
    
    tree[getnode()] = A[pos];
    seen.insert(A[pos]);
    parent[A[pos]] = 0;
    pos += 1;
                
    while (pos < N) {
        int base = get_parent(A[pos]);
        int ante = base;

        //cout << A[pos] << " " << tree[base] << "\n";
        
        while (tree[base] != -1) {
            ante = base;
            if (A[pos] > tree[base]) {
                if (mapper[base][1] == -1) {
                    mapper[base][1] = getnode();
                }
                base = mapper[base][1];
            } else {
                if (mapper[base][0] == -1) {
                    mapper[base][0] = getnode();
                }
                base = mapper[base][0];
            }
        }

        tree[base] = A[pos];        
        parent[tree[base]] = base;
        ans[pos] = tree[ante];
        seen.insert(A[pos]);
        pos += 1;
    }

    for (int i = 1; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
