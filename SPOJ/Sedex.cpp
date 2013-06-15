#include <iostream> 
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  int d, b, a, l;
  scanf("%d", &d);

  scanf("%d %d %d", &b, &a, &l);

  if(a >= d && b >= d  && l >= d) {
    cout << "S" << endl;
  } else {
    cout << "N" << endl;
  }
  return 0;
}
