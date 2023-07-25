#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define all(x) (x).begin(), (x).end()

int n, q;
string s;

void solve() {
  cin >> s; n = s.size();

  int ans = 1e9;
  for(int i=1; i<n-1; ++i) if (s[i] == 'O') {
    int need = i-1 + n-i-2;
    if (s[i-1] != 'M') ++need;
    if (s[i+1] != 'O') ++need;
    ans = min(ans, need);
  }

  cout << (ans == 1e9 ? -1 : ans) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  cin >> q;
  while (q--) solve();
  return 0;
}