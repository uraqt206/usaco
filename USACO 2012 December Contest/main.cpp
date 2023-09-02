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
#define file "art"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}


const int N = 1010;
int n, a[N][N], pre[N][N], bad[N * N], exist;

struct rect { 
  int u = N, v = N, p = -N, q = -N; 
} bound[N * N];

void add(int i, int x, int y) {
  bound[i].u = min(bound[i].u, x);
  bound[i].v = min(bound[i].v, y);
  bound[i].p = max(bound[i].p, x);
  bound[i].q = max(bound[i].q, y);
}

int main() {
  setIO();
  cin >> n;

  foru(i, 1, n) {
    foru(j, 1, n) {
      cin >> a[i][j];
      add(a[i][j], i, j);
    }
  }

  int disc = 0;
  foru(i, 1, n*n) {
    if (bound[i].u == N) continue;
    pre[bound[i].u][bound[i].v] += 1;
    pre[bound[i].p+1][bound[i].q+1] += 1;
    pre[bound[i].u][bound[i].q+1] -= 1;
    pre[bound[i].p+1][bound[i].v] -= 1;
    disc += 1;
  }
  if (disc == 1) return cout << n*n-1, 0;

  foru(i, 1, n) {
    foru(j, 1, n) {
      pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
      if (pre[i][j] > 1) bad[a[i][j]] = 1;
    }
  }

  int ans = 0;
  foru(i, 1, n*n) if (!bad[i]) ++ans;
  cout << ans;
}