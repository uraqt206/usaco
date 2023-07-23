#include <bits/stdc++.h>

#define FOR(i, l, r) for(int i=l; i<=r; ++i)
#define FOD(i, l, r) for(int i=r; i>=l; --i)
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "optmilk"

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mxn = 40040;
int n, q, a[mxn];
ll ret = 0;

struct date {
  ll fst, sec, thd, four;

  ll ans() {
    return max({fst, sec, thd, four});
  }
} sgt[mxn * 4];

date comb(date &x, date &y) {
  date ret;
  ret.fst = max(x.fst + y.fst, x.four + y.thd);
  ret.sec = max(x.thd + y.four, x.sec + y.sec);
  ret.thd = max(x.sec + y.thd, x.thd + y.fst);
  ret.four = max(x.fst + y.four, x.four + y.sec);
  return ret;
}

void upd(int i, int v, int id=1, int lb=1, int rb=n) {
  if (lb == rb) {
    a[i] = v;
    sgt[id] = {0, 0, 0, a[i]};
    return;
  }

  int mb = (lb + rb) >> 1;
  if (i <= mb) upd(i, v, id*2, lb, mb);
    else       upd(i, v, id*2+1, mb+1, rb);
  sgt[id] = comb(sgt[id*2], sgt[id*2+1]);
}

void garbage() {
  cin >> n >> q;

  for(int i=1; i<=n; ++i) {
    int x;
    cin >> x;
    upd(i, x);
  }

  for(int t=1; t<=q; ++t) {
    int i, v;
    cin >> i >> v;
    upd(i, v);
    ret += sgt[1].ans();
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

    int t=1;
//    cin >> t;
    for(int i=1; i<=t; ++i)
      garbage();
}
