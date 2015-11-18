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

int main(void) {
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,tmp;

int main(void) {
    while(cin >> n && n != 0) {
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 0; i < n; i++) { cin >> tmp; q.push(tmp); }
        int cost = 0;
        for(; q.size() >= 2; ) {
            int tmp = q.top(); q.pop(); tmp += q.top(); q.pop();
            cost += tmp;
            q.push(tmp);
        }
        cout << cost << endl;
    }
    return 0;
}
