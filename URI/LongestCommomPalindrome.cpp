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

int N, ans;
string S[14];
map<string, int> memo;

string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
vector<int> manacher(string s, int id) {
  string T = preProcess(s);
  int n = T.length();
  vector<int> P(n);

  map<string, bool> seen;

  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
	  int i_mirror = 2*C-i;
	  
	  P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
	  
	  while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
		  P[i]++;
	  }

	  int ulen = P[i];
	  while (ulen >= 1) {
		  string curr = s.substr((i - 1 - ulen)/2, ulen);
		  
		  if (curr != "" && !seen[curr]) {
			  seen[curr] = 1;
			  memo[curr] += 1;
			  
			  if (id == N - 1 && memo[curr] == N) {
				  chmax(ans, (int) curr.size());
			  }
		  }
		  ulen--;
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
	for ( ; cin >> N; ) {
		ans = 0;
		memo.clear();
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			manacher(S[i], i);
		}
		cout << ans << "\n";
	}
    return 0;
}
