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
#define file "taxi"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;

int n, m;
ll ret = 0;

void uraqt() {
  cin >> n >> m;

  vt<pii> a;
  vt<int> p(n + 3);

  for(int i=1; i<=n; ++i) {
    int l, r;
    cin >> l >> r;
    ret = ret + abs(r - l);

    a.push_back(C(l, 1));
    a.push_back(C(r, -1));
  }

  n = (n + 1) * 2;
  a.push_back(C(0, 1));
  a.push_back(C(m, -1));

  sort(all(a));
  for(int i=0; i<n; ++i)
    p[i + 1] = p[i] + a[i].se;

  for(int i=1; i<n; ++i) {
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
