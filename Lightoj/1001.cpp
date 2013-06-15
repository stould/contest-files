#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, x, a = 0;
  vector<int> v;
  
  cin >> n;

  while(n > 0) {
    cin >> x;
    if(binary_search(v.begin(), v.end(), x) == true) {
      int temp1 = a + 1;
      int temp2 = x - 1;
      cout << temp1 << " " << temp2 << endl;
    } else {
      cout << a << " " << x << endl;
    }
    v.push_back(x);
    sort(v.begin(), v.end());
    n--;
  }
  return 0;
}
