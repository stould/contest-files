#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int P, N;
string S[MAXN], L[MAXN], ori[MAXN];

vector<string> split(string arg) {
  vector<string> ans;
  string buff;
  istringstream ss(arg);

  while (ss >> buff) {
    ans.push_back(buff);
  }
  return ans;
}

int main() {
  while (cin >> P) {
    cin.ignore();
    map<string, int> mp;
    for (int i = 0; i < P; i++) {
      getline(cin, S[i]);

      for (int j = 0; j < (int) S[i].size(); j++) {
	if (S[i][j] >= 'A' && S[i][j] <= 'Z') {
	  S[i][j] = 'a' + (S[i][j] - 'A');
	}
      }
    }
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
      getline(cin, L[i]);

      ori[i] = L[i];
      
      for (int j = 0; j < (int) L[i].size(); j++) {
	if (L[i][j] >= 'A' && L[i][j] <= 'Z') {
	  L[i][j] = 'a' + (L[i][j] - 'A');
	}
      }
    }
    for (int i = 0; i < P; i++) {
      vector<string> vs = split(S[i]);
      
      for (int j = 0; j < (int) vs.size(); j++) {
	mp[vs[j]] += 1;
      }
    }
    
    for (int i = 0; i < N; i++) {
      cout << ori[i] << " " << mp[L[i]] << "\n";
    }
  }
  return 0;
}
