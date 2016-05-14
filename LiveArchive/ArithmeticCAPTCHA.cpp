#include <bits/stdc++.h>

using namespace std;

int T, N[5];

int main() {
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cin >> N[0] >> N[1] >> N[2] >> N[3];

    vector<char> P(5);

    P[0] = '=';
    P[1] = '+';
    P[2] = '-';
    P[3] = '*';

    char C1 = '=', C2 = '=', C3 = '=';

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
	for (int k = 0; k < 3; k++) {
	  if (i != 0 && j != 0 && k != 0) continue;
	  set<int> sp;
	  
	  int buff = 0;

	  buff += N[0];
	  
	  if (i == 0) {
	    sp.insert(buff);
	    buff = N[1];
	  } else if (i == 1) {
	    buff += N[1];
	  } else if (i == 2) {
	    buff -= N[1];
	  } else {
	    buff *= N[1];
	  }

	  if (j == 0) {
	    sp.insert(buff);
	    buff = N[2];
	  } else if (j == 1) {
	    buff += N[2];
	  } else if (j == 2) {
	    buff -= N[2];
	  } else {
	    buff *= N[2];
	  }

	  if (k == 0) {
	    sp.insert(buff);
	    buff = N[3];
	  } else if (k == 1) {
	    buff += N[3];
	  } else if (k == 2) {
	    buff -= N[3];
	  } else {
	    buff *= N[3];
	  }
	  
	  sp.insert(buff);

	  if (sp.size() == 1) {
	    C1 = P[i];
	    C2 = P[j];
	    C3 = P[k];
	    goto end;
	  }
	}
      }
    }
  end:;
    printf("Case #%d: %d %c %d %c %d %c %d\n", t, N[0], C1, N[1], C2, N[2], C3, N[3]);
    
  }
  return 0;
}
