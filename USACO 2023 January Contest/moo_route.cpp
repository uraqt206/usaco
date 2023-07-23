#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define all(x) (x).begin(), (x).end()

const int nx = 1e5+5;
int n, a[nx];

void solve() {
  cin >> n;
  for(int i=0; i<n; ++i) cin >> a[i];

  string ret;
  int cur = 0, dir = 0, sol = n;
  while (a[sol-1] == 0) --sol;

  while (sol > 0) {
    if (dir == 0) {
      if (cur < sol) {
        ret.ins('R');
        --a[cur];
        ++cur;
      } else dir = 1;
      continue;
    }

    if (a[cur-1] > 1 || (a[cur-1] == 1 && sol == cur)) {
      ret.ins('L');
      --cur;
      --a[cur];
      if (a[cur] == 0) sol = cur;
    } else dir = 0;
  }

  cout << ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
//    freopen("input.out", "w", stdout);
  }

  solve();
  return 0;
}