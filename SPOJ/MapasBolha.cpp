#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define _foreach(it, b, e) for(__typeof__(b) it = (b); it != (e); ++it)
#define foreach(x...) _foreach(x)

typedef long long int Int;

const int inf = 0x3f3f3f3f;
const Int hugeinf = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;

int N;

char up[255], dw[255], lf[255], rg[255];
string str;

int main(void) {
	cin >> N;

	up['p'] = dw['p'] = lf['r'] = rg['r'] = 's';
	up['q'] = dw['q'] = lf['s'] = rg['s'] = 'r';
	up['s'] = dw['s'] = lf['q'] = rg['q'] = 'p';
	up['r'] = dw['r'] = lf['p'] = rg['p'] = 'q';

	int i;

	for ( ; N--; )  {
		cin >> str;

		int len = (int) str.size(), ok;

		vector<string> ans(4, str);

        for (i = len - 1, ok = 0; i >= 0 && !ok; i--) {
            ans[0][i] = up[str[i]];

            if (str[i] == 's' || str[i] == 'r') {
                ok = 1;
            }
        }

        if (!ok) ans[0] = "<none>";

        for (i = len - 1, ok = 0; i >= 0 && !ok; i--) {
            ans[1][i] = dw[str[i]];

            if (str[i] == 'p' || str[i] == 'q') {
                ok = 1;
            }
        }

        if (!ok) ans[1] = "<none>";

        for (i = len - 1, ok = 0; i >= 0 && !ok; i--) {
            ans[2][i] = lf[str[i]];

            if (str[i] == 'q' || str[i] == 'r') {
                ok = 1;
            }
        }

        if (!ok) ans[2] = "<none>";

        for (i = len - 1, ok = 0; i >= 0 && !ok; i--) {
            ans[3][i] = rg[str[i]];

            if (str[i] == 'p' || str[i] == 's') {
                ok = 1;
            }
        }

        if (!ok) ans[3] = "<none>";

		for (i = 0; i < (int) ans.size(); i++) {
			cout << ans[i];
            if (i != (int) ans.size() - 1) cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
