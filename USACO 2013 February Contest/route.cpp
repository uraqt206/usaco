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
#define file "route"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 100010;

int n, m, r;
int a[mxn], b[mxn], F[mxn], G[mxn];
vt<pii> states;

void uraqt() {
  cin >> n >> m >> r;

  for(int i=1; i<=n; ++i)
    cin >> a[i];

  for(int i=1; i<=m; ++i)
    cin >> b[i];

  for(int i=1; i<=r; ++i) {
    int u, v;
    cin >> u >> v;
    states.push_back(C(u, v));
  }

  for(int i=1; i<=n; ++i)
    F[i] = a[i];
  for(int i=1; i<=m; ++i)
    G[i] = b[i];

  sort(all(states));
  for(int i=0; i<r; ++i) {
    int u = states[i].fi;
    int v = states[i].se;

    int vl = G[v] + a[u];
    int vr = F[u] + b[v];

    maximize(F[u], vl);
    maximize(G[v], vr);
  }

  cout << max(*max_element(F + 1, F + n + 1),
              *max_element(G + 1, G + m + 1));
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
        uraqt();
}
