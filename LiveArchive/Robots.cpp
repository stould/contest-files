#include <bits/stdc++.h>

typedef long long Int;

using namespace std;

int N, L, C;
deque<int> row[30];

int main(void) {
  while(1){
    for (int i = 0; i < 25; i++) {
      row[i].clear();
    }
    scanf("%d%d", &L, &C);
    if(L == -1 && C == -1) break;
    row[L].push_back(C);
      
    while(1){
      scanf("%d%d", &L, &C);
      if(L == 0 && C == 0) break;
      row[L].push_back(C);
    }

    for (int i = 0; i < 25; i++) {
      sort(row[i].begin(), row[i].end());
    }
    
    int ans = 0;

    while (true) {
      int col = 0;
      int used = 0;

      for (int i = 0; i < 25; i++) {
	if (!row[i].empty()) {
	  int cnt = 0;
	  int pr_col = col;
	  for (int j = 0; j < (int) row[i].size(); j++) {
	    if (row[i][j] >= col) {
	      col = row[i][j];
	      cnt += 1;
	    }
	  }
	  used += cnt;
	  while (!row[i].empty() && row[i].back() >= pr_col) {
	    row[i].pop_back();
	  }
	}
      }
      if (used == 0) break;
      ans += 1;
    }

    printf("%d\n", ans);
  }
  return 0;
}
