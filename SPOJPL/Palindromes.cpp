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

typedef long long Int;
typedef unsigned uint;

int K;
string S;

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
vector<int> manacher(string s) {
  string T = preProcess(s);
  int n = T.length();
  vector<int> P(n);

  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
	  int i_mirror = 2*C-i;
	  
	  P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
	  
	  while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
		  P[i]++;
	  }
 
	  if (i + P[i] > R) {
		  C = i;
		  R = i + P[i];
	  }
  }
  
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
	  if (P[i] > maxLen) {
		  maxLen = P[i];
		  centerIndex = i;
	  }
  }
  //to return actual longets substring
  //  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);

  // P[i] is the length of the largest palindrome centered at i
  return P;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin >> K >> S;
	
	vector<int> vp = manacher(S);
	int ans = 0;

	for (int i = 0; i < (int) vp.size(); i++) {
		if (vp[i] == K) {
			ans += 1;
		} else if (vp[i] > K) {
			if (vp[i] % 2 == K % 2) ans += 1;
		}
	}
	cout << ans << "\n";
    return 0;
}
