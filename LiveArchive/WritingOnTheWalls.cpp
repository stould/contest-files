#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long Hash;

const int MAXN = 50050;

int T;
string L, R;

Hash C1 = 5831ULL;
Hash B1 = 991ULL;

Hash C2 = 523ULL;
Hash B2 = 617ULL;

Hash C[MAXN][2];
Hash poww[MAXN][2];
Hash h[MAXN][2][2];

void pre() {
  poww[0][0] = 1ULL;
  poww[0][1] = 1ULL;

  C[0][0] = C1;
  C[0][1] = C2;
  
  for (int i = 1; i < MAXN; i++) {
    poww[i][0] = poww[i-1][0] * B1;
    poww[i][1] = poww[i-1][1] * B2;

    C[i][0] = C[i-1][0] * C1;
    C[i][1] = C[i-1][1] * C2;
  }
}

void buildHash(string arg, int id) {
  h[0][id][0] = 0ULL;
  h[0][id][1] = 0ULL; 

  for (int i = 1; i <= (int) arg.size(); i++) {
    h[i][id][0] = h[i - 1][id][0] * B1 + (arg[i - 1] - 'a');
    h[i][id][1] = h[i - 1][id][1] * B2 + (arg[i - 1] - 'a');
  }
}

pair<Hash, Hash> getHash(int id, int a, int b){
  Hash ha = h[b][id][0] - h[a][id][0] * poww[b-a][0] + C[b-a][0];
  Hash hb = h[b][id][1] - h[a][id][1] * poww[b-a][1] + C[b-a][1];

  return make_pair(ha, hb);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> T;
  
  pre();
  
  for (int t = 1; t <= T; t++) {
    cin >> L >> R;
    
    buildHash(L, 0);
    buildHash(R, 1);

    int ans = 0;
    
    //cout << getHash(0, 0, 1).first << "\n";
    
    for (int i = 0; i <= (int) L.size(); i++) {
      if (i > R.size()) break;
      pair<Hash, Hash> cl = getHash(0, L.size() - i, L.size());
      pair<Hash, Hash> cr = getHash(1, 0, i);
      
      
      if (cl.first == cr.first && cl.second == cr.second) {
	//cout << L.substr(L.size() - i - 1, i + 1) << " " << R.substr(0, i + 1) << "\n";
	//cout << L.substr(L.size() - i - 1, i + 1) << " ";
	//cout << R.substr(0, i + 1) << "\n";	
	//cout << cl.first << " " << cr.first << "\n";

      
	ans += 1;
      }
    }
    
    cout << ans << "\n";
  }
  return 0;
}
