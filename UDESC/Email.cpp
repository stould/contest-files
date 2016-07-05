#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;

int T, N, S;
string NM[MAXN];
vector<int> nx;
bool FL[MAXN][MAXN];

int main(void) {
	cin >> T;
  
	for (int t = 1; t <= T; t++) {
		cin >> N >> S;

		memset(FL, false, sizeof(FL));

		for (int i = 1; i <= N; i++) {
			cin >> NM[i];
		}
    
		for (int i = 1; i <= N; i++) {
			int cnt, nx;
			cin >> cnt;
      
			for (int j = 0; j < cnt; j++) {
				cin >> nx;
				FL[i][nx] = true;
			}
		}
    
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (FL[i][k] && FL[k][j]) {
						FL[i][j] = true;
					}
				}
			}
		}
    
		set<int> ans;
    
		for (int i = 1; i <= N; i++) {
			if (FL[S][i]) {
				for (int j = 1; j <= N; j++) {
					if (FL[i][j] && FL[j][i]) {
						ans.insert(i);
					}
				}
			}
		}
    
		cout << "E-Mail #" << t << ":\n";
    
		if (ans.size() <= 1) {
			cout << "E-Mail seguro!\n";
		} else {
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
				for (int i = 1; i <= N; i++) {
					if (FL[*it][i]) {
						ans.insert(i);
					}
				}
			}
			for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
				cout << NM[*it] << " ";
			}
			cout << "\n";
		}
    
		cout << "\n";
	}
	return 0;
}
