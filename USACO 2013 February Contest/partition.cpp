/* Trust The Process */

#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl
#define ll long long
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define len(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "partition"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 16;

bool on(int mask, int x) {
  return (mask & (1<<x)) > 0;
}

int n, k, ret = 1e9;
int cost[mxn][mxn], s[mxn], a[mxn][mxn];
vt<int> cur, prv;

int evaluate(int num, int mask) {
  for(int r1=1; r1<=n; ++r1) {
    memset(s, 0, sizeof(s));
    for(int r2=r1; r2<=n; ++r2) {
      cost[r1][r2] = 0;
      int tmp = 0;
      for(int c=1; c<=n; ++c) {
        s[c] += a[r2][c];
        tmp += s[c];
        cost[r1][r2] = max(cost[r1][r2], tmp);
        if (on(mask, c-1)) tmp = 0;
      }

//      cout << r1 << ' ' << r2 << ' ' << tmp << endl;
    }
  }

  ++num;
  prv.assign(n + 1, 1e9);
  prv[0] = 0;

  for(int rep=1; rep<=num; ++rep) {
    cur.assign(n + 1, 1e9);
    for(int i=1; i<=n; ++i)
      for(int j=0; j<i; ++j)
        cur[i] = min(cur[i], max(prv[j], cost[j + 1][i]));
    prv = cur;
  }

  return prv[n];
}

void uraqt() {
  cin >> n >> k;
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
    }
  }

  for(int mask=0; mask<(1<< (n - 1)); ++mask) {
    if (__builtin_popcount(mask) > k) continue;
    int v = evaluate(k - (int)__builtin_popcount(mask), mask);
    ret = min(ret, v);
  }

  cout << ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(file".in", "r")) {
        freopen(file".in", "r", stdin);
        freopen(file".out", "w", stdout);
    }

    int t=1;
//    cin >> t;
    for(int i=1; i<=t; ++i)
        uraqt();
}
