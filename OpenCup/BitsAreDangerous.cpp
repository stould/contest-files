#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

string S;
int N;
long long L[MAXN], R[MAXN];

void build_l() {
	int i = 0;
	int last_l;
	int beg;
  
	while (i < N && S[i] == '0') {
		i += 1;
	}
	beg = i;
	last_l = i;
	i++;
  
	for ( ; i < N; i++) {
		if (S[i] == '1') {
			L[i] = last_l;
			last_l = i;
		}
	}

	for (i = N - 1; i >= 0; i--) {
		if (S[i] == '1') {
			L[beg] = i;
			break;
		}
	}
}

void build_r() {
	int i = N - 1;
	int last_r;
	int beg;
  
	while (i >= 0 && S[i] == '0') {
		i -= 1;
	}
	beg = i;
	last_r = i;
	i--;
  
	for ( ; i >= 0; i--) {
		if (S[i] == '1') {
			R[i] = last_r;
			last_r = i;
		}
	}

	for (i = 0; i < N; i++) {
		if (S[i] == '1') {
			R[beg] = i;
			break;
		}
	}
}

long long begin_l(int cnt) {
	int pos;
	long long ans = 0;

	vector<long long> bl(N), br(N);

	for (int i = 0; i < N; i++) {
		bl[i] = L[i];
		br[i] = R[i];
	}  
  
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] == '1') {
			pos = i;
			break;
		}
	}

	ans += (N - pos) * 7;

	for ( ; cnt > 0; cnt--) {
        int r = br[pos];
		int l = bl[pos];

		long long dist_r;
		long long dist_l;

		if (pos <= r) {
			dist_r = min(r - pos, pos + (N - r));
		} else {
			dist_r = min(pos - r, (N - pos) + r);
		}

		if (pos <= l) {
			dist_l = min(l - pos, pos + (N - l));
		} else {
			dist_l = min(pos - l, (N - pos) + l);
		}
    
		int expos = pos;
		long long df = 0;
    
		if (dist_r < dist_l) {
			df += dist_r * 7;
			pos = r;
		} else {
			df += dist_l * 7;
			pos = l;
		}

		ans += df;
    
		//cerr << expos << " " << r << " " << l << " - " << dist_r << " " << dist_l << " = " << df << "\n";
    
		int nl = bl[expos];
		int nr = br[expos];
    
		br[nl] = r;
		bl[nr] = l;    
	}

	return ans;
}

long long begin_r(int cnt) {
	int pos;
	long long ans = 0;

	vector<long long> bl(N), br(N);

	for (int i = 0; i < N; i++) {
		bl[i] = L[i];
		br[i] = R[i];
	}  
  
	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			pos = i;
			break;
		}
	}

	ans += pos * 7;

	for ( ; cnt > 0; cnt--) {
		int r = br[pos];
		int l = bl[pos];
    
		long long dist_r;
		long long dist_l;
    
		if (pos <= r) {
			dist_r = min(r - pos, pos + (N - r));
		} else {
			dist_r = min(pos - r, (N - pos) + r);
		}

		if (pos <= l) {
			dist_l = min(l - pos, pos + (N - l));
		} else {
			dist_l = min(pos - l, (N - pos) + l);
		}
    
		int expos = pos;
		long long df = 0;
    
		if (dist_r <= dist_l) {
			df += dist_r * 7LL;
			pos = r;
		} else {
			df += dist_l * 7LL;
			pos = l;
		}

		ans += df;
    
		//cerr << expos << " " << r << " " << l << " - " << dist_r << " " << dist_l << " = " << df << "\n";
    
		int nl = bl[expos];
		int nr = br[expos];
    
		br[nl] = r;
		bl[nr] = l;    
	}

	return ans;
}

int main() {
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);
  
	cin >> S;

	N = (int) S.size();

	int seen_one = 0;

	for (int i = 0; i < N; i++) {
		if (S[i] == '1') {
			seen_one += 1;
		}
	}

	if (!seen_one) {
		cout << "0\n";
	} else {
		build_l();
		build_r();

		long long pl = begin_l(seen_one);
		long long pr = begin_r(seen_one);
    
		cout << 4LL * seen_one + min(pl, pr) << "\n";  
	}
  
	return 0;
}
