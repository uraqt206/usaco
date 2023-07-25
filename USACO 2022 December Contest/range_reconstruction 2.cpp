  #include <bits/stdc++.h>
  using namespace std;
  using ll = long long;
  using pii = pair<int, int>;
  using pll = pair<ll, ll>;

  #define ins push_back
  #define vec vector
  #define all(x) (x).begin(), (x).end()

  const int lim = 2e9;
  const int nx = 302;

  int n, a[nx], r[nx][nx];

  bool check(int i) {
    int mx = -lim, mn = lim;
    for(int j=i; j<=n; ++j) {
      mx = max(mx, a[j]);
      mn = min(mn, a[j]);
      if (mx - mn != r[i][j]) return 0;
    }
    return 1;
  }

  void solve() {
    cin >> n;

    for(int i=1; i<=n; ++i)
      for(int j=i; j<=n; ++j)
        cin >> r[i][j];

    a[n] = 0;
    for(int i=n-1; i>=1; --i) {
      a[i] = a[i+1] + r[i][i+1];
      if (check(i)) continue;
      a[i] = a[i+1] - r[i][i+1];
    }

    for(int i=1; i<=n; ++i) {
      if (i > 1) cout << " ";
      cout << a[i];
    }
  }

  int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("input.inp", "r")) {
      freopen("input.inp", "r", stdin);
      freopen("input.out", "w", stdout);
    }

    solve();
  }
