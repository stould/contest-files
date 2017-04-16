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

const int MAXN = 500005;

int N;
int P[MAXN];
Int A[MAXN];

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];   
        A[i] = MAXN;
    }

    A[1] = 0;
    
    queue<int> q;    
    q.push(1);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (P[now] != now && A[P[now]] > A[now] + 1) {
            A[P[now]] = A[now] + 1;
            q.push(P[now]);
        }
        if (now + 1 <= N && A[now + 1] > A[now] + 1) {
            A[now + 1] = A[now] + 1;
            q.push(now + 1);
        }
        if (now - 1 >= 0 && A[now - 1] > A[now] + 1) {
            A[now - 1] = A[now] + 1;
            q.push(now - 1);
        }

    }
    
    for (int i = 1; i <= N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    return 0;
}
