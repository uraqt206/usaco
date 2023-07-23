#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nx = 1e5+5;
int n, e[nx], pg[nx], ph[nx];
string s;

void solve() {
  cin >> n >> s;
  for(int i=0; i<n; ++i) cin >> e[i];

  int mh = 0, mg = 0, fh = -1, fg = -1;
  for(int i=0; i<n; ++i) {
    if (s[i] == 'G') {
      if (fg == -1) fg = i+1;
      mg = i+1;
      ++pg[i+1];
      --pg[e[i]+1];
    }

    if (s[i] == 'H') {
      if (fh == -1) fh = i+1;
      mh = i+1;
      ++ph[i+1];
      --ph[e[i]+1];
    }
  }

  for(int i=0; i<n; ++i) {
    pg[i+1] += pg[i];
    ph[i+1] += ph[i];
  }

  int ans = 0;
  int cnt = 0;

  if (e[fg - 1] >= mg) {
    if (fg <= fh && e[fg - 1] >= fh) --ans;
    ++cnt;
    ans += ph[fg];
  }

//  cout << ans << "\n";

  if (e[fh - 1] >= mh) {
    if (fh <= fg && e[fh - 1] >= fg) --ans;
    ++cnt;
    ans += pg[fh];
  }

//  cout << mg << " " << mh << " " << cnt << "\n";
  cout << ans + (cnt == 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  solve();
  return 0;
}