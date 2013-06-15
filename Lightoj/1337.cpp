#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, times = 0;

int dx[] = {0, 1,  0, -1};
int dy[] = {1, 0, -1,  0};

void dfs(char** array, int x, int y, int m, int n) {
  if(array[x][y] == '#') {
    return;
  } else {
    for(int i = 0; i < 4; i++) {
      int xa = dx[i] + x;
      int ya = dy[i] + y;
      bool flag = false;

      if(xa >= 0 && xa < n && ya >= 0 && ya < m && array[xa][ya] != 'X') {
	  if(array[xa][ya] == 'C') {
	    array[xa][ya] = 'X';
	    times++;
	    flag = true;
	  }
	  if(array[xa][ya] == '.') {
	    flag = true;
	  }
	  if(flag) {
	    dfs(array, xa, ya, m, n);
	  }
	}
    }
  }
}

int main() {
  int i, j, t, q, x, y, caso = 1;
  char buff;

  cin >> t;

  while(t > 0) {
    cin >> m >> n >> q;
    char array[m][n];

    for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
	cin >> buff;
	array[i][j] = buff;
      }
    }
    cout << "Case " << caso++ << ":" << endl;
    while(q > 0) {
      cin >> x >> y;
      dfs(array, x - 1, y - 1, m, n);
      cout << times << endl;
      times = 0;
      q--;
    }
    t--;
  }
  return 0;
}
