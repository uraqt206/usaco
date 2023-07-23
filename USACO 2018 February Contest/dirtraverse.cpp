#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const ll LINF = 1e18;
const int INF = 2e9;
const int N = 1e5+5;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int n, k, a[N];
ll ans = LINF, cnt[N], dp[N];
vector<int> graph[N];

void dfs(int u) {
  for(int v : graph[u]) {
    dfs(v);
    cnt[u] += cnt[v];
    dp[u] += dp[v] + (a[v]+(graph[v].size()>0)) * cnt[v];
  }
  if (graph[u].empty()) {
    cnt[u] = 1;
    dp[u] = 0;
  }
}

void reroot(int u) {
  ans = min(ans, dp[u]);
  for(int v : graph[u]) {
    if (graph[v].empty()) continue;

    cnt[u] -= cnt[v];
    dp[u] -= dp[v] + (a[v]+1) * cnt[v];
    cnt[v] += cnt[u];
    dp[v] += 3 * cnt[u] + dp[u];

    reroot(v);

    cnt[v] -= cnt[u];
    dp[v] -= 3 * cnt[u] + dp[u];
    cnt[u] += cnt[v];
    dp[u] += dp[v] + (a[v]+1) * cnt[v];
  }
}

void solve() {
  cin >> n;

  foru(i, 1, n) {
    string s; cin >> s;
    a[i] = s.size();

    int m; cin >> m;
    foru(j, 1, m) {
      int k; cin >> k;
      graph[i].push_back(k);
    }
  }

  dfs(1);
  reroot(1);
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("dirtraverse.in", "r")) {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
  }


  solve();
}