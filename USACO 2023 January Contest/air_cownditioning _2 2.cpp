#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define all(x) (x).begin(), (x).end()

struct air {
  int a, b, p, m;
  air(int _a=0, int _b=0, int _p=0, int _m=0) : a(_a), b(_b), p(_p), m(_m) {}
};

struct cow {
  int a, b, c;
  cow(int _a=0, int _b=0, int _c=0) : a(_a), b(_b), c(_c) {}
};

int n, m;
vec<air> airs;
vec<cow> cows;

void solve() {
  cin >> n >> m;

  for(int i=0; i<n; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    cows.emplace_back(s, t, w);
  }

  for(int i=0; i<m; ++i) {
    int a, b, p, m;
    cin >> a >> b >> p >> m;
    airs.emplace_back(a, b, p, m);
  }

  int ans = 1e9;
  for(int mask=0, full=1<<m; mask<full; ++mask) {
    vec<int> cover(102);
    int cost = 0;

    for(int i=0; i<m; ++i) if (mask >> i & 1) {
      cover[airs[i].a] += airs[i].p;
      cover[airs[i].b+1] -= airs[i].p;
      cost += airs[i].m;
    }

    for(int i=1; i<=100; ++i)
      cover[i] += cover[i-1];

    bool ok = 1;
    for(int i=0; i<n && ok; ++i) {
      for(int j=cows[i].a; j<=cows[i].b; ++j)
        if (cover[j] < cows[i].c) {
          ok = 0;
          break;
        }
    }

    if (ok) ans = min(ans, cost);
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

  solve();
  return 0;
}