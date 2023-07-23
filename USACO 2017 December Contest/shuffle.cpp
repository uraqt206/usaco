/*
USACO 2017 December Contest, Silver
Problem 3. The Bovine Shuffle
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db = double;

#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define fi first
#define se second
#define vec vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define C make_pair
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "shuffle"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int MAX = 1e5+5;
int n, par[MAX];

void underated() {
  cin >> n;
  rep(i, 1, n) {
    cin >> par[i];
  }

  vec<int> who(n+1, -1);
  int ret = 0;

  rep(i, 1, n) if (who[i] == -1) {
    who[i] = 0;
    int a = par[i], b = par[par[i]];

    for(; a^b && who[a]==-1; a=par[a], b=par[par[b]])
      who[a] = 0;

    if (a^b) continue;
    do {
      who[a] = 1;
      a = par[a];
    } while (a ^ b);
  }

  rep(i, 1, n) if (who[i]>0)
    ++ret;

  cout << ret;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }

  underated();
  return 0;
}
