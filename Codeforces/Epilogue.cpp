#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int INF = INT_MAX / 4;

int N, M;
int CS[MAXN], MI[MAXN];
vector<pair<int, int> > A, B;
//idA idB
pair<int, int> tree[4 * MAXN];

int pos(int v, vector<pair<int, int> >& arg) {
	int l = 0, h = N - 1, m;
	int best = INF;
	
	while (l <= h) {
		m = (l + h) / 2;
		
		if (arg[m].first > v) {
			best = min(best, m);
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	if (best == INF) best = N;
	return best;
}

void build(int node, int l, int r) {
	if (l > r) {
		return;
	} else if (l == r) {
		tree[node] = make_pair(A[l].second, B[l].second);
	} else {
		int m = (l + r) / 2;
		
		build(2 * node, l, m);
		build(2 * node + 1, m + 1, r);

		tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
		tree[node].second = min(tree[2 * node].second, tree[2 * node + 1].second);
	}
}

pair<int, int> query(int node, int l, int r, int bl, int br) {
	if (l > r || l > br || r < bl) {
		return make_pair(INF, INF);
	} else if (l >= bl && r <= br) {
		return tree[node];
	} else {
		int m = (l + r) / 2;

		pair<int, int> ql = query(2 * node, l, m, bl, br);
		pair<int, int> qr = query(2 * node + 1, m + 1, r, bl, br);

		return make_pair(min(ql.first, qr.first), min(ql.second, qr.second));
	}
}

int main(void) {
	cin >> N;	

	for (int i = 0; i < N; i++) {
		int curr;
		cin >> curr;
		A.push_back(make_pair(curr, i));
	}
	for (int i = 0; i < N; i++) {
		int curr;
		cin >> curr;
		B.push_back(make_pair(curr, i));
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	build(1, 0, N - 1);
	
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> CS[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> MI[i];
		
//		vector<pair<int, int> >::iterator ia = lower_bound(A.begin(), A.end(), make_pair(CS[i] + 1, -10000));
	//	vector<pair<int, int> >::iterator ib = lower_bound(B.begin(), B.end(), make_pair(MI[i] + 1, -10000));
	
		
		//int lCS = (ia != A.end()) ? ia->second : N;
//		int lMI = (ib != B.end()) ? ib->second : N;
		int lCS = pos(CS[i], A);
		int lMI = pos(MI[i], B);

		//cout << lCS << " " << lMI << "\n";
		if (lCS != N) {
			lCS = query(1, 0, N - 1, lCS, N - 1).first;
		}
		if (lMI != N) {
			lMI = query(1, 0, N - 1, lMI, N - 1).second;
		}
		//ut << lCS << " " << lMI << "\n";
//		cout << lCS << " " << lMI << "\n";		
//		cout << CS[i] << " -> " << lCS << " = " << MI[i] << " -> " << lMI << "\n";  
//		cout << "CS " << i << "\n";
		if (lCS == lMI || (lCS >= N && lMI >= N)) {
			cout << "Draw\n";
		} else {
			if (lCS < lMI) {
				cout << "Mike\n";	
			} else {
				cout << "Constantine\n";
			}
		}
	}
	return 0;
}
