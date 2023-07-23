/* Trust The Process */
/* Chua Accepted */

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
#define file "recording"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 150 + 5;

int n, dp[301][301];
vt<int> comp, en[301];
pair<int, int> evts[301];

int pos(int x) {
    return upper_bound(all(comp), x) - comp.begin();
}



void uraqt() {
  cin >> n;

  for(int i=1; i<=n; ++i) {
    cin >> evts[i].fi >> evts[i].se;

    comp.push_back(evts[i].fi);
    comp.push_back(evts[i].se);
  }

  sort(all(comp));
  comp.erase(unique(all(comp)), comp.end());

  for(int i=1; i<=n; ++i) {
    evts[i].fi = pos(evts[i].fi);
    evts[i].se = pos(evts[i].se);

    dp[evts[i].se][0] = 1;
    dp[0][evts[i].se] = 1;

    en[evts[i].se].push_back(evts[i].fi);
  }

  // for(int i=1; i<=n; ++i) {
    // cout << pos(evts[i].fi) << " " << pos(evts[i].se) << endl;
  // }

  // debug(comp.size());
  // cout << "------------------\n\n";

  // for(int i=1; i<=10; ++i) {
  //    for(int j: en[i])
  //        cout << j << ' ';
  //    cout << endl;
  // }

  int ret = 0;
  for(int i=1; i<=300; ++i) {
    for(int j=1; j<=300; ++j) {
        if (en[i].size() == 0) continue;
        if (en[j].size() == 0) continue;

        // if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        // if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);

        for(int lst: en[i])
            ckmax(dp[i][j], dp[lst][j] + 1);
        for(int lst: en[j])
            ckmax(dp[i][j], dp[i][lst] + 1);

        // if (i != j) {
        //  for(int lst_i : en[i])
        //      for(int lst_j : en[j])
        //          ckmax(dp[i][j], dp[lst_i][lst_j] + 2);
        // } else {
        //  for(int x=0; x<en[i].size(); ++x)
        //      for(int y=0; y<en[i].size(); ++y) if (x != y)
        //          ckmax(dp[i][j], dp[en[i][x]][en[i][y]] + 2);
        // }
        ret = max(ret, dp[i][j]); 
    }
  }

  for(int i=1; i<=10; ++i) {
    for(int j=1; j<=10; ++j)
        cout << dp[i][j] << ' ';
    cout << endl;
  }

  // cout << dp[300][300];
  cout << ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  if (fopen(file".in", "r")) {
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
  }

  int t=1;
  // cin >> t;
  for(int i=1; i<=t; ++i)
      uraqt();  
}
