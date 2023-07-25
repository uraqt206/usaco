#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define mask(i) (1 << (i-1))

const int mod = 1e9+7;
const int N = 1e5+5, M = 1<<20;

int exp(int n, int k) {
  if (k == 0) return 1;
  int tmp = exp(n, k/2);
  tmp = 1LL * tmp * tmp % mod;
  if (k & 1) tmp = 1LL * tmp * n % mod;
  return tmp;
}

int n, m;
int hard[N], cnt[M], dp[M], pre[M][21];
int f[N], inv[N];

int ways(int n) {
  int ans = mod-1;
  for(int i = 0; i <= n; ++i) {
    int tmp = 1LL * f[n] * inv[i] % mod;  
    ans += tmp;
    if (ans >= mod) ans -= mod;
  }
  return ans;
}

void solve() {
  cin >> n >> m;

  f[0] = inv[0] = 1;
  for(int i = 1; i <= n; ++i) {
    f[i] = 1LL * f[i-1] * i % mod;
    inv[i] = exp(f[i], mod-2);
  }

  for(int i = 0; i < m; ++i) {
    string s;
    cin >> s;

    for(int j = 0; j < n; ++j)
      if (s[j] == 'H')
        hard[j] += (1 << i);
  }

  for(int i = 0; i < n; ++i) {
    cnt[hard[i]] += 1;
    // cout << bitset<6>(hard[i]) << "\n";
  }

  for(int i = 0; i < (1 << m); ++i) {
    int tmp = ways(cnt[i]);

    for(int j = 1; j <= m; ++j) {
      pre[i][j] = pre[i][j-1];
      if (i & mask(j)) pre[i][j] += pre[i - mask(j)][j - 1];
      if (pre[i][j] >= mod) pre[i][j] -= mod;
    }
    
    pre[i][0] = 1LL * pre[i][m] * tmp % mod;
    pre[i][0] += tmp;
    if (pre[i][0] >= mod) pre[i][0] -= mod;

    for(int j = 1; j <= m; ++j) {
      pre[i][j] += pre[i][0];
      if (pre[i][j] >= mod) pre[i][j] -= mod;
    }
  }

  int ans = 0;
  for(int i = 0; i < (1 << m); ++i) {
    ans += pre[i][0];
    if (ans >= mod) ans -= mod;
  }

  cout << ans;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  solve();
}
