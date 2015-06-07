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

int N, K, P, X, Y;

pair<int, int> sit(vector<int> vd, vector<int> ad, int sum) {
	for (int i = 0; i < (int) ad.size(); i++) {
		vd.push_back(ad[i]);
		sum += ad[i];
	}
	sort(vd.begin(), vd.end());
	
	pair<int, int> ans = make_pair(0, 0);

	if (sum > X) {
		ans.first = 1;
	}

	//for (int i = 0; i < (int) vd.size(); i++) {
	//	cerr << vd[i] << " ";
		
	//}
	//cerr << "\n";
	
	//cerr << "Sum " << sum << " " << "Median " << vd[(vd.size() + 1) / 2] << "\n";
	
	if (vd[vd.size() / 2] < Y) {
		ans.second = -1;
	}

	return ans;
}

void incBeg(vector<int>& v) {
	for (int i = 0; i < (int) v.size(); i++) {
		if (v[i] < P) {
			v[i] += 1;
			break;
		}
	}
}

void decBeg(vector<int>& v) {
	for (int i = 0; i < (int) v.size(); i++) {
		if (v[i] != 1) {
			v[i] -= 1;
			break;
		}
	}
}

void incEnd(vector<int>& v) {
	for (int i = (int) v.size() - 1; i >= 0; i--) {
		if (v[i] < P) {
			v[i] += 1;
			break;
		}
	}
}

void decEnd(vector<int>& v) {
	for (int i = (int) v.size() - 1; i >= 0; i--) {
		if (v[i] != 1) {
			v[i] -= 1;
			break;
		}
	}
}

int main(void) {
	scanf("%d%d%d%d%d", &N, &K, &P, &X, &Y);

	vector<int> vs(K);
	int sum = 0;
	
	for (int i = 0; i < K; i++) {
		scanf("%d", &vs[i]);
		sum += vs[i];
	}

	vector<int> ad;
	
	for (int i = K; i < N; i++) {
		ad.push_back(1);
	}

	bool ok = false;
	
	for (int x = 0; x < (N - K) * P; x++) {
		pair<int, int> now = sit(vs, ad, sum);
		
		//cerr << now.first << " " << now.second << "\n";
		
		//for (int i = 0; i < (int) ad.size(); i++) {
			//cerr << ad[i] << " ";
		//}
		//cerr << "\n";

		if (now.first == 0 && now.second == 0) {
			ok = true;
			break;
		}

		sort(ad.begin(), ad.end());
		
		if (now.first != 0) {
			if (now.second == -1) {
				decEnd(ad);
			} else {
				decBeg(ad);
			}
		} else {
			if (now.second != -1) {
				incBeg(ad);
			} else {
				incEnd(ad);
			}
		}
	}
		
	if (!ok) {
		printf("-1\n");
	} else {
		for (int i = 0; i < (int) ad.size(); i++) {
			printf("%d ", ad[i]);
		}
		printf("\n");
	}
	
	return 0;
}
