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
typedef unsigned uint;

const int MAXN = 1010;

int N, S;
int P[MAXN], Q[MAXN];
char D[MAXN];

int main(void) {
	cin >> N >> S;

	vector<pair<int, int> > vb, vs;
	
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> P[i] >> Q[i];

		if (D[i] == 'B') {
			vb.push_back(make_pair(P[i], Q[i]));
		} else {
			vs.push_back(make_pair(P[i], Q[i]));
		}
	}

	sort(vb.rbegin(), vb.rend());
	sort(vs.rbegin(), vs.rend());
	
	vector<pair<int, int> > vans_s, vans_b;

	for (int i = 0; i < (int) vs.size(); i++) {
		int j = i;
		int q = 0;

		while (j < (int) vs.size() && vs[j].first == vs[i].first) {
			q += vs[j].second;
			j++;
		}
		vans_s.push_back(make_pair(vs[i].first, q));
		//cout << "S " << vs[i].first << " " << q << "\n";
		i = j - 1;		
	}
	
	for (int i = 0; i < (int) vb.size(); i++) {
		int j = i;
		int q = 0;

		while (j < (int) vb.size() && vb[j].first == vb[i].first) {
			q += vb[j].second;
			j++;
		}
		vans_b.push_back(make_pair(vb[i].first, q));
		//cout << "B " << vb[i].first << " " << q << "\n";
		i = j - 1;		
	}

	sort(vans_s.begin(), vans_s.end());
		 
	for (int i = 0; i < min(S, (int) vans_s.size()); i++) {
		cout << "S " << vans_s[min(S, (int) vans_s.size()) - i - 1].first << " " << vans_s[min(S, (int) vans_s.size()) - i - 1].second << "\n";
	}
	for (int i = 0; i < min(S, (int) vans_b.size()); i++) {
		cout << "B " << vans_b[i].first << " " << vans_b[i].second << "\n";
	}
	
	return 0;
}
