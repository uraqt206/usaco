#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define fi first
#define se second
#define C make_pair
#define ar array

const int N = 1e5+5;
int n, m;
vector<int> graph[N], obs[N];

void make(int p) {
  for(int i=1; i<=n; ++i) {
    graph[i].clear();
  }

  for(int i=1; i<=p; ++i) {
    for(int j=0; j<sz(obs[i])-1; ++j) {
      // graph[obs[i][j+1]].push_back(obs[i][j]);
      graph[obs[i][j]].push_back(obs[i][j+1]);
    }
  }
}

int sta[N];

bool dfs(int u) {
  sta[u] = 1;
  for(int v : graph[u]) {
    if (sta[v] == 2) continue;
    if (sta[v] == 1) return 1;
    if (dfs(v)) return 1;
  }
  sta[u] = 2;
  return 0;
}

bool check(int p) {
  make(p);
  fill(sta, sta+n+1, 0);  
  for(int i=1; i<=n; ++i) if (sta[i] == 0) 
    if (dfs(i)) return 0;
  return 1;
}

int deg[N];
priority_queue<int> pq;

void calc(int p) {
  make(p);
  vector<int> ans;

  for(int i=1; i<=n; ++i)
    for(int j : graph[i])
      deg[j]++;

  for(int i=1; i<=n; ++i) {
    if (deg[i] == 0) {
      pq.push(-i);
    }
  }

  while (!pq.empty()) {
    int u = -pq.top(); pq.pop();
    ans.push_back(u);
    for(int v : graph[u]) if (--deg[v] == 0) {
      pq.push(-v);
    }
  }

  for(int i=0; i<n; ++i) {
    cout << ans[i];
    if (i<n-1) cout << " ";
  }
}

void solve() {
  cin >> n >> m;

  for(int i=1; i<=m; ++i) {
    int num; cin >> num;
    for(int j=0; j<num; ++j) {
      int node; cin >> node;
      obs[i].push_back(node);
    }
  }

  int at=0;
  for(int z=m; z>0; z>>=1) 
    while (at+z <= m && check(at+z))
      at += z;

  calc(at);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("milkorder.in", "r")) {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
  }


  solve();
}