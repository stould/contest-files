#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define REV(i, a, n) for((i) = a; i > n; i--)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;

string func(int n, int b) {
   string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUWXYZ", ans = "";

   while(n > 0) {
      ans = bases[n % b] + ans;
      n /= b;
   }
   return ans;
}

int a, b;
int mx = 0;

int main(void) {
    cin >> a >> b;

    int s = a + b;

    for(int i = 2; i <= 20; i++) {
        string tmp = func(s, i);
        cout << tmp << endl;
        mx = max(mx, (int) tmp.size());
    }
    cout << mx << endl;

    return 0;
}
