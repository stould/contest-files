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

const int MAXN = 100005;

int N;
int P[MAXN];
map<int, int> mp;

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		mp[P[i]] += 1;
	}

	vector<int> can;
	map<int, int>::iterator it, nx;
	
	for (it = mp.begin(); it != mp.end(); it++) {
		int val = it->first;

		if (it->second >= 2) {
			can.push_back(val);
		} else {
			nx = it;
			nx++;
			
			if (nx->first == val + 1 && it->second + nx->second >= 2) {
				can.push_back(val);
			}
		}
	}

	reverse(can.begin(), can.end());

	Int ans = 0LL;
	
	for (int i = 0; i < (int) can.size(); i++) {
		int side_a = can[i];
		
		for (int j = i; j < (int) can.size(); j++) {
			int side_b = can[j];

			int buf_a = mp[side_a];
			int buf_b = mp[side_b];

			bool got_a = false;
			bool got_b = false;
						
			int us_a = min(2, mp[side_a]);
			mp[side_a] -= us_a;

			if (us_a < 2 && mp[side_a + 1] > 0) {
				us_a += 1;
				mp[side_a + 1] -= 1;
				got_a = true;
			}

			int us_b = min(2, mp[side_b]);
			mp[side_b] -= us_b;

			if (us_b < 2 && mp[side_b + 1] > 0) {
				us_b += 1;
				mp[side_b + 1] -= 1;
				got_b = true;
			}

			if (us_a >= 2 && us_b >= 2) {
				ans += side_a * (Int) side_b;
			} else {
				mp[side_a] = buf_a;
				mp[side_b] = buf_b;
				
				if (got_a) mp[side_a + 1] += 1;
				if (got_b) mp[side_b + 1] += 1;				
			}

			if (us_a < 2) break;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
