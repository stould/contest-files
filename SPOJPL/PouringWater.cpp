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

int T, A, B, C;

pair<int, int> pourAonB(int pa, int pb) {
	pair<int, int> ans = make_pair(0, 0);

	if (pa + pb <= B) {
		ans.first = 0;
		ans.second = pa + pb;
	} else {
		ans.first = pa - (B - pb);
		ans.second = B;
	}

	return ans;
}

pair<int, int> pourBonA(int pa, int pb) {
	pair<int, int> ans = make_pair(0, 0);

	if (pa + pb <= A) {
		ans.first = pa + pb;
		ans.second = 0;
	} else {
		ans.second = pb - (A - pa);
		ans.first = A;
	}

	return ans;
}


int main(void) {
	cin >> T;

	for ( ; T--; ) {
		cin >> A >> B >> C;

		int ans = -1;
		
		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));

		map<pair<int, int>, int> vis;

		vis[make_pair(0, 0)] = 0;

		for ( ; !q.empty(); ) {
			int pa = q.front().first;
			int pb = q.front().second;
			
			//cout << pa << " "<< pb << "\n";
			
			pair<int, int> now = q.front();
			
			q.pop();
			
			if (pa == C || pb == C) {
				ans = vis[make_pair(pa, pb)];
				break;
			}

			pair<int, int> fA = make_pair(A, pb);

			if (vis.find(fA) == vis.end()) {
				vis[fA] = vis[now] + 1;
				q.push(fA);
			}

			pair<int, int> fB = make_pair(pa, B);

			if (vis.find(fB) == vis.end()) {
				vis[fB] = vis[now] + 1;
				q.push(fB);
			}

			pair<int, int> fEA = make_pair(0, pb);
						
			if (vis.find(fEA) == vis.end()) {
				vis[fEA] = vis[now] + 1;
				q.push(fEA);
			}

			pair<int, int> fEB = make_pair(pa, 0);

			if (vis.find(fEB) == vis.end()) {
				vis[fEB] = vis[now] + 1;
				q.push(fEB);
			}

			
			pair<int, int> pAB = pourAonB(pa, pb);
			
			if (vis.find(pAB) == vis.end()) {
				vis[pAB] = vis[now] + 1;
				q.push(pAB);
			}

			pair<int, int> pBA = pourBonA(pa, pb);

			if (vis.find(pBA) == vis.end()) {
				vis[pBA] = vis[now] + 1;
				q.push(pBA);
			}			
		}

		cout << ans << "\n";
	}
	return 0;
}
