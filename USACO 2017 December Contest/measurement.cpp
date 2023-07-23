/*
USACO 2017 December Contest, Silver
Problem 2. Milk Measurement
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db = double;

#define deb(x) cout << #x << ": " << x << "\n"
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
#define file "measurement"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int MAX = 1e5+5;

int onion(vec<int> &a, int i) {
  return lower_bound(all(a), i) - a.begin();
}

void underated() {
  int N, G;

  cin >> N >> G;

  vec<pair<int, pii>> querys;
  vec<int> compID;

  rep(i, 1, N ) {
    int t, id, c;
    char ch;
    cin >> t >> id >> ch >> c;
    compID.push_back(id);
    if (ch == '+')
      querys.push_back(C(t, C(id, c)));
    else
      querys.push_back(C(t, C(id, -c)));
  }

  sort(all(compID));
  uni(compID);

  int ret = 0;
  vec<int> cnt(N, G);
  multiset<int> ms(all(cnt));
  map<int, int> mp;
  mp[G] = N;

  sort(all(querys));


  for(auto evts: querys) {
    int cows = onion(compID, evts.se.fi), delta = evts.se.se;

    int nax1 = *ms.rbegin(), cnt1 = mp[nax1];
    bool u1 = (cnt[cows] == nax1);

    ms.erase(ms.find(cnt[cows]));
    --mp[cnt[cows]];
    cnt[cows] += delta;
    ++mp[cnt[cows]];
    ms.insert(cnt[cows]);

    int nax2 = *ms.rbegin(), cnt2 = mp[nax2];
    bool u2 = (cnt[cows] == nax2);

    if ((cnt1 ^ cnt2) || (u1 ^ u2))
      ++ret;
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
