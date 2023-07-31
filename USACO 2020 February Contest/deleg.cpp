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
#define file "deleg"

void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, sub[N], cnt[N];
vec<int> graph[N], num[N];

void dfs(int u, int p) {
  sub[u] = 1;
  fore(v, graph[u]) if (v != p) {
    dfs(v, u);
    sub[u] += sub[v];
    num[u].push_back(sub[v]);
  }
}

int main() {
  setIO();
  cin >> n;

  foru(i, 2, n) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1, 0);
  foru(k, 1, n-1) {
    if ((n-1)%k!=0) { cout << 0; continue; }
    bool good = 1;
    foru(i, 1, n) {
      cnt[i] = 0;
    }
    foru(i, 1, n) {
      int tmp = (sub[i]-1) % k, bad = 0;
      if (tmp > 0) cnt[k - tmp] += 1, bad = 1;
      fore(v, num[i]) {
        int val = v % k;
        if (val == 0) continue;
        if (cnt[k-val]) --cnt[k-val], --bad;
        else ++cnt[val], ++bad;
      }
      if (bad) { good = 0; break; }
    }
    cout << good;
  }
}
