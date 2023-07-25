#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l; i>=(r); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int INF = 1e9;
const int N = 1e5+5;
// const int SQRT = sqrt(N);
int SQRT;

int n, k;

struct block {
  int mn = INF, mx = -INF;
  vector<int> a;

  block(vector<int> _a = {}) : a(_a) {
    for(int x : a) {
      mn = min(mn, x);
      mx = max(mx, x);
    }
  }

  bool through(int val) {
    return val-k <= mn && mx <= val+k;
  }

  bool should(int val) {
    for(int i=a.size()-1; i>=0; --i) {
      if (abs(a[i] - val) > k) return 0;
      if (val <= a[i]) return 1;
    }
    return a.empty();
  }

  void insert(int val) {
    a.push_back(val); mn = min(mn, val); mx = max(mx, val);
    int j = a.size()-1;
    while (j > 0 && abs(val - a[j-1]) <= k) --j;
    while (j < a.size() && val > a[j]) ++j;
    rotate(a.begin()+j, a.end()-1, a.end());
  }

  void out() {
    for(int x : a) cout << x << "\n";
  }
};

vector<block> range;

void solve() {
  cin >> n >> k;
  SQRT = sqrt(n);

  range.emplace_back();
  for(int i=1; i<=n; ++i) {
    int cur;
    cin >> cur;

    int j = sz(range)-1;
    while (j > 0 && range[j].through(cur)) --j;
    if (!range[j].should(cur)) ++j;
    while (j < sz(range) && cur > range[j].mx) ++j;
    if (j == sz(range)) range.emplace_back();
    range[j].insert(cur);


    if (sz(range[j].a) > SQRT) {
      int mid = sz(range[j].a)/2;
      vector<int> &a = range[j].a;
      vector<int> _left = vector<int>(a.begin(), a.begin() + mid);
      vector<int> _right = vector<int>(a.begin()+mid, a.end());
      range[j] = _left;
      range.insert(range.begin() + j + 1, block(_right));
    }
  }

  for(auto x : range) {
    x.out();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }
 
  solve();
}