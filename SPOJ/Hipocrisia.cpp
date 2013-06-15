#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int instances, n, d, x, y, i, j, tmp;

bool ok(int xa, int ya, int xb, int yb) {
  return (int) abs(xa - xb) + abs(ya - yb) <= d;
}

int main(void) {
  scanf("%d", &instances);
  for(; instances-- > 0; ) {
    scanf("%d%d", &n, &d);
    vector<pair<int, int> > vp(n);
    vector<int> dist(n, 0);
    for(i = 0; i < n; i++) {
      scanf("%d%d", &vp[i].first, &vp[i].second); 
      for(j = i - 1; j >= 0; j--) {
	if(ok(vp[i].first, vp[i].second, vp[j].first, vp[j].second)) {
	  dist[i] += 1;
	  dist[j] += 1;
	}
      }
    }
    for(i = 0; i < n; i++) {
      printf("%d ", dist[i]);
    }
    printf("\n");
  }
  return 0;
}
