#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define lc id<<1
#define rc id<<1|1
#define x first
#define y second
#define right _right
#define left _left

const int N = 1e5+5;
const int INF = 1e9;

int n, nx, ny;
ii a[N];
vector<int> vx, vy, block[N];

int pos(vector<int> &comp, int v) { 
  return upper_bound(all(comp), v) - comp.begin();
}

struct ft {
  int bit[N];

  void upd(int i, int v) {
    for(; i<=ny; i+=i&-i) bit[i] += v; 
  }

  int query(int l, int r) {
    if (l == ny+1 || r == 0) return 0;
    if (l > r) return 0;
    int ans = 0;
    for(int u=r; u>0; u-=u&-u) ans += bit[u];
    for(int u=l-1; u>0; u-=u&-u) ans -= bit[u];
    return ans;
  }
} left, right;

int ans = INF;

void calc() {
  for(int i=1; i<=n; ++i) {
    vx.push_back(a[i].x);
    vy.push_back(a[i].y);
  }

  sort(all(vx)); 
  vx.resize(unique(all(vx)) - vx.begin()); 
  nx = vx.size();
  sort(all(vy));
  vy.resize(unique(all(vy)) - vy.begin());
  ny = vy.size();

  for(int i=1; i<=n; ++i) {
    int px = pos(vx, a[i].x);
    int py = pos(vy, a[i].y);
    right.upd(py, 1);
    block[px].push_back(py);
  }
  
  for(int i=1; i<=nx; ++i) {
    for(int py : block[i]) {
      right.upd(py, -1);
      left.upd(py, 1);
    }

    int bor, z;

    for(bor=0, z=ny>>1; z>0; z>>=1) 
      while (bor+z <= ny && max(left.query(1, bor), right.query(1, bor)) < max(left.query(bor+1, ny), right.query(bor+1, ny)))
        bor += z;
    ans = min(ans, max(left.query(1, bor+1), right.query(1, bor+1)));

    for(bor=ny+1, z=ny>>1; z>0; z>>=1)
      while (bor-z >= 1 && max(left.query(1, bor-z-1), right.query(1, bor-z-1)) > max(left.query(bor-z, ny), right.query(bor-z, ny)))
        bor -= z;
    ans = min(ans, max(left.query(bor-1, ny), right.query(bor-1, ny)));
  }
}

void solve() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    cin >> a[i].x >> a[i].y;
  }

  calc();
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  if (fopen("balancing.in", "r")) {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
  }

  solve();
}