#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define file "input"
#define lc id<<1 // hennnnnnnnnnn
#define rc id<<1|1
#define int long long

void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 2e5+5;
int n, a[N], pos[N], prv[N];

struct node {
  ll act, uni, val, lazy;
  node(ll _act=0, ll _uni=0, ll _val=0, ll _lazy=0) : act(_act), uni(_uni), val(_val), lazy(_lazy) {} 
} sgt[N*4];

void push(int id, int lb, int mb, int rb) {
  if (sgt[id].lazy == 0) return;
  int k = id<<1;
  ll val = sgt[id].lazy;
  sgt[k].uni += val * (mb - lb + 1);
  sgt[k].val += val * sgt[k].act;
  sgt[k].lazy += val;
  sgt[k|1].uni += val * (rb - mb);
  sgt[k|1].val += val * sgt[k|1].act;
  sgt[k|1].lazy += val;
  sgt[id].lazy = 0;
}

void build(int id, int lb, int rb) {
  sgt[id].act = (rb - lb + 1);
  if (lb ^ rb) {
    int mb = (lb + rb) >> 1;
    build(lc, lb, mb);
    build(rc, mb+1, rb);
  }
}

void modify(int id, int lb, int rb, int l, int r, int val) {
  if (l <= lb && rb <= r) {
    sgt[id].uni += val * (rb - lb + 1);
    sgt[id].val += val * sgt[id].act;
    sgt[id].lazy += val;
    return;
  } else if (lb > r || rb < l) 
    return;
  int mb = (lb + rb) >> 1;
  push(id, lb, mb, rb);
  modify(lc, lb, mb, l, r, val);
  modify(rc, mb+1, rb ,l, r, val);
  sgt[id].val = sgt[lc].val + sgt[rc].val;
  sgt[id].uni = sgt[lc].uni + sgt[rc].uni;
  sgt[id].act = sgt[lc].act + sgt[rc].act;
}

void update(int id, int lb, int rb, int i) {
  if (lb ^ rb) {
    int mb = (lb + rb) >> 1;
    push(id, lb, mb, rb);
    if (i <= mb) update(lc, lb, mb, i);
    else update(rc, mb+1, rb, i);
    sgt[id].val = sgt[lc].val + sgt[rc].val;
    sgt[id].uni = sgt[lc].uni + sgt[rc].uni;
    sgt[id].act = sgt[lc].act + sgt[rc].act;
  } else {
    sgt[id].act ^= 1;
    sgt[id].val = sgt[id].act * sgt[id].uni;
  }
}

int query(int id, int lb, int rb, int l, int r) {
  if (l <= lb && rb <= r) return sgt[id].val;
  if (lb > r || rb < l) return 0;
  int mb = (lb + rb) >> 1;
  push(id, lb, mb, rb);
  return query(lc, lb, mb, l, r) + query(rc, mb+1, rb, l, r);
}

void modify(int l, int r, int val) {
  // cout << "Modify " << l << " " << r << " " << val << "\n";
  modify(1, 1, n, l, r, val);
}

void update(int i) {
  // cout << "Flip " << i << "\n";
  update(1, 1, n, i);
}

ll query(int l, int r) {
  // cout << "Query " << l << " " << r << "\n";
  return query(1, 1, n, l, r);
}

signed main() {
  setIO();

  cin >> n;
  foru(i, 1, n) cin >> a[i];
  build(1, 1, n);

  foru(i, 1, n) {
    prv[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  
  ll ret = 0;

  // foru(i, 1, n) {
  //   cout << prv[i] << " ";
  // }
  // cout << "\n";

  foru(i, 1, n) {
    // cout << "i " << i << "\n";
    // if (prv[i] > 0) {
      if (prv[i] > 0) modify(prv[prv[i]] + 1, prv[i] - 1, -1);  
      if (prv[i] > 0) update(prv[i]);
      ret += query(prv[i]+1, i);
      // cout << query(prv[i]+1, i) << "\n";
      modify(prv[i] + 1, i - 1, 1);
    // }
    // foru(i, 1, n) {
    //   cout << query(1, 1, n, i, i) << " ";
    // }
    // cout << "\n";
  }

  cout << ret;
}