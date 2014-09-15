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
#include <numeric>
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

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

const int INF = INT_MAX / 3;
const int MAXN = 2020;

int I, N, M, P;
int C[MAXN], V[MAXN];
int dp[MAXN][MAXN];
vector<int> pr;

int func(int curr_y, int m_age) {
    if (curr_y == N) {
      return 0;
    } else if (m_age > M) {
      return INF;
    } else {   
      int& ans = dp[curr_y][m_age];
     
      if (ans == -1) {  
    int a = (P - V[m_age]) + C[0] + func(curr_y + 1, 1);
    int b = C[m_age] + func(curr_y + 1, m_age + 1);
    
    if (m_age == M) {
      ans = a;
    } else {
      if (a <= b) {
        ans = a;   
      } else {
        ans = b;   
      }
    }   
      }
      return ans;
    }
}

void print_path(int curr_y, int m_age) {
  if (curr_y == N || m_age > M) {
    return;   
  } else {
    int a = (P - V[m_age]) + C[0] + func(curr_y + 1, 1);
    int b = C[m_age] + func(curr_y + 1, m_age + 1);
   
    if (m_age == M) {
      pr.push_back(curr_y + 1);
      print_path(curr_y + 1, 1);
    } else {
      if (a <= b) {
    pr.push_back(curr_y + 1);
    print_path(curr_y + 1, 1);
      } else {
    print_path(curr_y + 1, m_age + 1);
      }
    }       
  }
}

int main(void) {
  for ( ; scanf("%d%d%d%d", &N, &I, &M, &P) == 4; ) {
    for (int i = 0; i < M; i++) {
      C[i] = in();
    }
    for (int i = 1; i <= M; i++) {
      V[i] = in();
    }
   
    memset(dp, -1, sizeof(dp));
   
    int ans = func(0, I);
   
    printf("%d\n", ans);

    pr.clear();
    print_path(0, I);
   
    if (pr.empty()) {
      printf("0\n");
    } else {
      for (int i = 0; i < (int) pr.size(); i++) {
    if (i != 0) printf(" ");
    printf("%d", pr[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
