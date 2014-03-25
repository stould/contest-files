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

int N;

int main(void) {
	N = in();

	priority_queue<int> q;

	for (int i = 0; i < N; i++) {
		q.push(in());
	}

	for ( ; ; ) {
		int a = q.top(); 
		q.pop();
		
		vector<int> buff;
		buff.clear();

		for ( ; !q.empty(); ) {
			int b = q.top();
			q.pop();

			if (a - b > 0) {
				q.push(b);
				q.push(a - b);
				break;
			} else {
				buff.push_back(b);
		   }
		}
		bool done = false;
		if (q.empty()) {
			q.push(a);
			done = true;
		}
		for (int i = 0; i < (int) buff.size(); i++) {
			q.push(buff[i]);
		}
		if (done) {
			break;
		}
	}
	
	int ans = 0;

	for ( ; !q.empty(); ) {
		ans += q.top();
		q.pop();
	}
	printf("%d\n", ans);
    return 0;
}
