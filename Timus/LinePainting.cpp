#include <iostream>
#include <map>
#include <set>
#include <vector>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 5002;

int N;
int A[MAXN], B[MAXN];
char C[MAXN];
int tree[4 * MAXN];

int query(int node, int l, int r, int bl, int br) {
	if (l > r or l > br or r < bl) {
		return 0;
	} else if (l >= bl && r <= br) {
		return tree[node];
	} else {
		int m = (l + r) / 2;
		
		return query(2 * node, l, m, bl, br) + query(2 * node + 1, m + 1, r, bl, br);
	}
}

void update(int node, int l, int r, int bl, int br, int val) {
	if (l > r or l > br or r < bl) {
		return;
	} else if (l == r) {
		tree[node] = val;
	} else {
		int m = (l + r) / 2;
		
		update(2 * node, l, m, bl, br, val);
		update(2 * node + 1, m + 1, r, bl, br, val);

		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}

int main(void) {
	cin >> N;

	set<int> comp;
	map<int, int> id, rev;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];

		comp.insert(A[i]);
		comp.insert(B[i]);		
	}

	int pos = 0;
	for (set<int>::iterator it = comp.begin(); it != comp.end(); it++) {
		id[*it] = pos;
		rev[pos] = *it;
		pos++;
	}

	for (int i = 0; i < N; i++) {
		int l = id[A[i]];
		int r = id[B[i]];

		if (C[i] == 'w') {
			update(1, 0, pos - 1, l, r, 0);
		} else {
			update(1, 0, pos - 1, l, r, 1);
		}

		cout << l << " " << r << " " << C[i] << " => " << A[i] << " " << B[i] << endl;;
		for (int j = 0; j < pos; j++) {
			cout << query(1, 0, pos - 1, j, j) << " " ;
		}
		cout << endl;
		
	}

	vector<int> vf(pos + 1);
	
	for (int i = 0; i < pos; i++) {
		vf[i] = query(1, 0, pos - 1, i, i);
		cout << vf[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < pos; i++) {
		cout << rev[i] << " ";
	}
	cout << endl;

	int l = 0, r = 0;
	
	for (int i = 0; i < pos; i++) {
		if (vf[i] == 0) {
			int j = i;

			while (j < pos && vf[j] == 0) {
				j += 1;
			}
			j -= 1;

			int pl = rev[0];
			int pr = rev[j];
			
			if (i != 0) {
				pl = rev[i - 1];
			} else {
				pl = 0;
			}

			if (j == pos - 1) {
				pr = 1000000000;
			}

			cout << pl << " " << pr << endl;
			
			if (pr - pl + 1 > r - l + 1) {
				l = pl;
				r = pr;
			}
			
			i = j + 1;
		}
	}

	cout << l << " " << r << endl;
	return 0;
}
