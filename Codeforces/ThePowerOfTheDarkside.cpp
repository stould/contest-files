#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {
  int i;

  cin >> N;

  vector<tuple<int, int, int, int> > vt(N);

  tuple<int, int, int, int> best;

  for (i = 0; i < N; i++) {
    cin >> get<0>(vt[i]) >> get<1>(vt[i]) >> get<2>(vt[i]);

    get<3>(vt[i]) = i + 1;

    if (get<0>(vt[i]) > get<1>(vt[i])) swap(get<0>(vt[i]), get<1>(vt[i]));
    if (get<0>(vt[i]) > get<2>(vt[i])) swap(get<0>(vt[i]), get<2>(vt[i]));
    if (get<1>(vt[i]) > get<2>(vt[i])) swap(get<1>(vt[i]), get<2>(vt[i]));

    if (get<0>(vt[i]) > get<0>(best)) {
      get<0>(best) = get<0>(vt[i]);
    }
    if (get<1>(vt[i]) > get<1>(best)) {
      get<1>(best) = get<1>(vt[i]);
    }
    if (get<2>(vt[i]) > get<2>(best)) {
      get<2>(best) = get<2>(vt[i]);
    }
  }

  if (get<0>(best) > get<1>(best)) swap(get<0>(best), get<1>(best));
  if (get<0>(best) > get<2>(best)) swap(get<0>(best), get<2>(best));
  if (get<1>(best) > get<2>(best)) swap(get<1>(best), get<2>(best));

  sort(vt.begin(), vt.end());

  vector<int> ans;

  for (i = 0; i < N; i++) {
    if (get<1>(vt[i]) > get<0>(best) && get<2>(vt[i]) > get<1>(best)) {
      ans.push_back(get<3>(vt[i]));
    }
  }

  cout << (int) ans.size() << "\n";

  sort(ans.begin(), ans.end());

  for (i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
