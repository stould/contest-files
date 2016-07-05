#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;

int N, D[MAXN], M[MAXN];

int main() {
  while (cin >> D[0] >> M[0]) {
    if (D[0] == 0 && M[0] == 0) break;
    
    cin >> N;

    bool ok = false;
    
    for (int i = 1; i <= N; i++) {
      cin >> D[i] >> M[i];
      
      if (D[i] == D[0] && M[i] == M[0]) {
	ok = true;
      }
    }

    if (ok) {
      cout << "S\n";
    } else {
      cout << "N\n";
    }
  }
  return 0;
}
