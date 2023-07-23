#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define C make_pair
#define fi first
#define se second

const ll LINF = 1e18;
const int INF = 2e9;
const int MOD = 1e9+7;
const int N = 5005;

int exp(int n, int k) {
  if (k == 0) return 1;
  int tmp = exp(n, k/2);
  tmp = 1LL * tmp * tmp % MOD;
  if (k & 1) tmp = 1LL * tmp * n % MOD;
  return tmp;
}

ii words[N];
int n, m, k, same[26], dp[N], ways[N];

void add(int &a, int b) { if ((a+=b) >= MOD) a -= MOD; }

void solve() {
  cin >> n >> m >> k;

  dp[0] = 1;
  for(int i=1; i<=n; ++i) {
    int s, c;
    cin >> s >> c;
    words[i] = C(s, c);
  }

  for(int i=0; i<=k; ++i) {
    for(int j=1; j<=n; ++j) if (i+words[j].fi <= k) {
      if (i+words[j].fi == k) add(ways[words[j].se], dp[i]);
      else add(dp[i+words[j].fi], dp[i]);
    }
  }

  for(int i=1; i<=m; ++i) {
    char c; 
    cin >> c;
    ++same[c-'A'];
  }

  int ans = 1;
  for(int i=0; i<26; ++i) if (same[i] > 0) {
    int total = 0;
    for(int j=1; j<=n; ++j) add(total, exp(ways[j], same[i]));
    ans = 1LL * ans * total % MOD;
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("poetry.in", "r")) {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
  }


  solve();
}