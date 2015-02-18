#include <bits/stdc++.h>

using namespace std;

int buff;

int main(void) {
  for ( ; scanf("%d", &buff) && buff != -1; ) {
    vector<int> vs;
    for ( ; ; ) {
      if (buff == 0) break;
      vs.push_back(buff);
      scanf("%d", &buff);
    }
    
    sort(vs.begin(), vs.end());

    int ans = 0;

    for (int i = 1; i <= 99; i++) {
      if (binary_search(vs.begin(), vs.end(), 2 * i)) {
	if (binary_search(vs.begin(), vs.end(), i)) {
	  ans += 1;
	}
      }
    }

    printf("%d\n", ans);
  }
  return 0;
}
