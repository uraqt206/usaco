#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
template<class T> using vec = vector<T>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define file "gathering"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, m, ans[N];
vec<int> adj[N], cond[N], deg1(N), deg2(N);

void dfs(int u, int p) {
  ans[u] = 1;
  fore(v, adj[u]) if (v != p) {
    if (!cond[v].empty()) continue;
    dfs(v, u);
  }
}

int main() {
  setIO();

  cin >> n >> m;

  foru(i, 2, n) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); deg1[u] += 1;
    adj[v].push_back(u); deg1[v] += 1;
  }

  foru(i, 1, m) {
    int u, v;
    cin >> u >> v;
    cond[u].push_back(v); deg2[v] += 1;
  }

  int lst, cnt = 0;
  vec<int> have, rem(n+1);

  foru(i, 1, n) if (deg1[i] == 1 && deg2[i] == 0) {
    have.push_back(i);
    rem[i] = 1;
  }

  while (!have.empty()) {
    lst = have.back(); have.pop_back();
    cnt += 1;
    
    fore(v, cond[lst]) if (!rem[v]) {
      if (--deg2[v] == 0 && deg1[v] <= 1) {
        have.push_back(v);
        rem[v] = 1;
      }
    }

    fore(v, adj[lst]) if (!rem[v]) {
      if (--deg1[v] <= 1 && deg2[v] == 0) {
        have.push_back(v);
        rem[v] = 1;
      }
    }
  }

  if (cnt == n) dfs(lst, lst);
  foru(i, 1, n) cout << ans[i] << "\n";
}