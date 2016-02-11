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

const int MAXN = 20020;

int T, N, D;
int S[1050][1050];

int main(void) {
	cin >> T;

	while (T--) {
		cin >> D >> N;

		memset(S, 0, sizeof(S));
		
		int bestSum = 0;
		int ans_x = -1, ans_y = -1;
		
		for (int i = 0; i < N; i++) {
			int xa, ya, rat;
			cin >> xa >> ya >> rat;
			
			for (int a = xa - D; a <= xa + D; a++) {
				for (int b = ya - D; b <= ya + D; b++) {
					if (a >= 0 && b >= 0 && a <= 1024 && b <= 1024) {
						S[a][b] += rat;
					}
				}
			}
		}
		for (int i = 0; i <= 1024; i++) {
			for (int j = 0; j <= 1024; j++) {
				if (S[i][j] > bestSum) {
					bestSum = S[i][j];
					ans_x = i;
					ans_y = j;
				}
			}
		}
		/*
		sort(P, P + N);

		set<pair<pair<int, int>, int> > active;
		
		for (int i = 0; i < N; i++) {
			active.insert(P[i]);
			//cout << P[i].first.first << " " << P[i].first.second << "\n";
			while (active.size() > 1 && P[i].first.first - (*active.begin()).first.first > 2 * D) {
				active.erase(active.begin());
			}

			int sum = 0;
			set<pair<pair<int, int>, int> > y_active;
			
			for (const auto& curr : active) {
				y_active.insert(curr);
				sum += curr.second;
				//cerr << "Adding " << curr.second << " Sum = " << sum << "\n";
				while (y_active.size() > 1 && curr.first.second - (*y_active.begin()).first.second > 2 * D) {
					//cerr << "Removing " << (*y_active.begin()).second << "\n";
					sum -= (*y_active.begin()).second;					
					y_active.erase(y_active.begin());
				}				
				//cout << "Sum " << y_active.size() << " " << sum << "\n";

				int nx = (*y_active.begin()).first.first  + (((curr.first.first  - (*y_active.begin()).first.first ) / 2));
				int ny = (*y_active.begin()).first.second + (((curr.first.second - (*y_active.begin()).first.second) / 2));
				
				if (y_active.size() == 1) {
					nx = max(0, nx - D);
					ny = max(0, ny - D);
				}

				//cout << nx << " " << ny << " " << sum << " => " << m_dist(nx, ny, curr.first.first, curr.first.second) << "\n";;
				while (nx - 1 >= 0 && m_dist(nx - 1, ny, curr.first.first, curr.first.second) <= D) {
					nx -= 1;
				}
				while (ny - 1 >= 0 && m_dist(nx, ny - 1, curr.first.first, curr.first.second) <= D) {
					ny -= 1;
				}
								
				//cout << sum << " " << nx << " " << ny << "\n";

				if (bestSum < sum || (bestSum == sum && (ans_x > nx || (ans_x == nx && ans_y > ny)))) {
					bestSum = sum;
					//cout << bestSum << "\n";

					//int nx = active.begin()).first.first  + (((*y_active.begin()).first.first  - curr.first.first) / 2);
					//int ny = (*y_active.begin()).first.second + (((*y_active.begin()).first.second - curr.first.second) / 2);
					//cerr << (*y_active.begin()).first.first << " " <<  (*y_active.begin()).first.second << "\n";
					//cerr << curr.first.first << " " <<  curr.first.second << "\n";
					//cerr << nx << " " << ny << "\n";
					ans_x = nx;
					ans_y = ny;
				}
			}
			}
		*/
		cout << ans_x << " " << ans_y << " " << bestSum << "\n";
	}
	return 0;
}
