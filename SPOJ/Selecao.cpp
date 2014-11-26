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

const int MOD = 1000000007;

int N, X;
priority_queue<int, vector<int>, greater<int> > minHeap;
priority_queue<int, vector<int>, less<int> > maxHeap;


int median_retrieve(void) {
	if (minHeap.empty() && maxHeap.empty()) return 0;

	if (minHeap.size() == maxHeap.size()) {
		return min(minHeap.top(), maxHeap.top());
	} else {
		if (minHeap.size() > maxHeap.size()) {
			return minHeap.top();
		} else {
			return maxHeap.top();
		}
	}
}

void median_insert(int x) {
	if (x > median_retrieve()) {
		minHeap.push(x);
	} else {
		maxHeap.push(x);
	}
	
	while (abs((int) (minHeap.size() - maxHeap.size())) > 1) {
		if (minHeap.size() > maxHeap.size()) {
			int tmp = minHeap.top();
			minHeap.pop();
			maxHeap.push(tmp);
		} else {
			int tmp = maxHeap.top();
			maxHeap.pop();
			minHeap.push(tmp);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);

	cin >> N;

	Int ans = 0LL;

	for (int i = 0; i < N; i++) {
		cin >> X;
		median_insert(X);
		ans += median_retrieve();
		ans %= MOD;
	}

	cout << ans << "\n";

    return 0;
}
