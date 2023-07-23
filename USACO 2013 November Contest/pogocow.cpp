#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using T = double;

#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, l, r) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define file "pogocow"

const int nx = 1002;

int n, dp[nx][nx];
pii a[nx];

int calc() {
  memset(dp, -0x3f, sizeof(dp));

  int ans = 0;
  foru(i, 1, n) {
    dp[i][i] = a[i].second;
    foru(j, 1, i-1) {
      int dis = abs(a[j].first - a[i].first);

      int lb = 1, rb = i, mb;
      while (lb < rb) {
        mb = (lb + rb) >> 1;
        if (abs(a[mb].first - a[j].first) <= dis) rb = mb;
        else lb = mb+1;
      }

      dp[i][j] = dp[j][lb] + a[i].second;
    }

    revu(j, 1, i)
      dp[i][j] = max(dp[i][j], dp[i][j+1]);
    ans = max(ans, dp[i][1]);
  }

  return ans;
}

void solve() {
  cin >> n;
  foru(i, 1, n) cin >> a[i].first >> a[i].second;

  int ans = 0;
  sort(a+1, a+n+1);
  ans = max(ans, calc());
  reverse(a+1, a+n+1);
  ans = max(ans, calc());

  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }

  int t = 1;
  // cin >> t;
  while (t--) solve();

  return 0;
}
