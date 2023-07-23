#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a[50005], dp[2][50005];

bool can(int power) {
  ll range = power*2;
  for(int i=1, j=1; i<=n; ++i) {
    while (a[i]-a[j] > range) ++j;
    if (power >= max(dp[0][j], dp[1][n-i+1])+2) return 1;
  }
  return 0;
}

void solve() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    a[i] *= 2;
  }

  sort(a+1, a+n+1);
  for(int r=0; r<2; ++r) {
    int j = 0;
    for(int i=2; i<=n; ++i) {
      while (j < i-1 && abs(a[i]-a[j+1]) >= dp[r][j+1]) ++j;
      dp[r][i] = max(abs(a[i]-a[j]), dp[r][j]+2);
      if (j < i-1) dp[r][i] = min(dp[r][i], max(abs(a[i]-a[j+1]), dp[r][j+1]+2));
    }
    reverse(a+1, a+n+1);
  }

  int lb = 0, rb = 2e9+1, mb;
  while (lb < rb) {
    mb = (lb + rb) >> 1;
    if (can(mb)) rb = mb;
    else lb = mb+1;
  }

  cout << lb/2 << (lb & 1 ? ".5" : ".0");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  solve();
}