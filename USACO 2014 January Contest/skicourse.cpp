/*
USACO 2014 January Contest, Gold
Problem 2. Building a Ski Course

Link: http://usaco.org/index.php?page=viewproblem2&cpid=383
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define deb(x) cout << #x << ": " << x << "\n"
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define fi first
#define se second
#define vec vector
#define C make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "skicourse"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int MAX = 120;
int n, m;
bool isR[MAX][MAX], isS[MAX][MAX];

void underated() {
  cin >> n >> m;

  rep(i, 1, n) {
    rep(j, 1, m) {
      char ch; cin >> ch;
      if (ch == 'R')
        isR[i][j] = 1;
      else
        isS[i][j] = 1;
    }
  }

  vec<pii> cur(m+1), prv(m+1);

  int ret = n+1;
  while (true) {
    fill(all(prv), C(0, 0));

    int best = -1, r = -1, c = -1;
    rep(i, 1, n) {
      rep(j, 1, m) {
        pii &node = cur[j];

        node.fi = (isR[i][j] ? min({cur[j-1].fi, prv[j].fi, prv[j-1].fi}) + 1 : 0);
        node.se = (isS[i][j] ? min({cur[j-1].se, prv[j].se, prv[j-1].se}) + 1 : 0);

        if (node.fi ^ node.se) {
          int local = max(node.fi, node.se);
          if (local > best) {
            best = local;
            r = i;
            c = j;
          }
        }
      }

      prv.swap(cur);
    }

    if (best == -1) break;
    rep(i, 1, n)
    ckmin(ret, best);

    rep(i, r-best+1, r)
      rep(j, c-best+1, c)
        isS[i][j] = isR[i][j] = 1;
  }

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
