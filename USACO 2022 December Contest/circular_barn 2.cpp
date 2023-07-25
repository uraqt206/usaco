#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ins push_back
#define vec vector
#define all(x) (x).begin(), (x).end()

const int lim = 1e9;
const int nx = 2e5+5, mxv = 5e6;
int n, m, dp[mxv+1], mx[4];

bool bad[mxv+1];
void sieve() {
  bad[0] = bad[1] = 1;
  mx[1] = 1;

  for(int i=1; i<=mxv; ++i) {
    if (!bad[i] && i <= mxv/i)
      for(int j=i*i; j<=mxv; j+=i)
        bad[j] = 1;

    if (!bad[i]) mx[i%4] = i;

    if (i & 1) dp[i] = dp[i-mx[i%4]] + 1;
    else dp[i] = i/2;
  }
}

void solve() {
  cin >> n;

  pair<int, int> ans = {lim, 0};

  for(int i=1; i<=n; ++i) {
    int x; cin >> x;

    int need = dp[x]/2 + 1;
    if (need < ans.first) ans = {need, (x % 4 == 0)};
  }

  cout << (ans.second == 0 ? "Farmer John\n" : "Farmer Nhoj\n");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  sieve();

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
