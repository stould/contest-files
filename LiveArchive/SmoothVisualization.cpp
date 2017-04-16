#include <bits/stdc++.h>

using namespace std;

int T;
string S;

string func(int x, int mx) {
  string ans = "";

  for (int i = 0; i < x; i++) {
    ans += "+";
  }

  while (ans.size() < mx) {
    ans = "*" + ans;
  }

  return ans;
}

int main() {
  cin >> T;

  while (cin >> S) {
    vector<string> arg;
    int mx = 0;
    
    for (int i = 0; i < (int) S.size(); i++) {
      mx = max(mx, S[i] - '0');
    }
    
    for (int i = 0; i < (int) S.size(); i++) {
      if (i == 0) {
	arg.push_back(func(S[i] - '0', mx));
      } else {
	if (S[i - 1] < S[i]) {
	  for (int j = S[i - 1] - '0' + 1; j <= S[i] - '0'; j++) {
	    arg.push_back(func(j, mx));
	  }
	} else if (S[i - 1] > S[i]) {
	  for (int j = S[i - 1] - '0' - 1; j >= S[i] - '0'; j--) {
	    arg.push_back(func(j, mx));
	  }
	} else {
	  arg.push_back(func(S[i] - '0', mx));
	}
      }
    }

    for (int i = 0; i < mx; i++) {
      for (int j = 0; j < arg.size(); j++) {
	cout << arg[j][i];
      } 
      cout << "\n";
    }
  }
  return 0;
}
