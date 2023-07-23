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
#define file "slowdown"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

#define int long long

const int mod = 1e9 + 7;
const int mxn = 200;
const int K = 22;
const double EPI = 0.000001;

vt<int> fst, sec;
int N;

void uraqt() {
  cin >> N;

  for(int i=1; i<=N; ++i) {
    char cmd;
    cin >> cmd;

    int x;
    cin >> x;
    if (cmd == 'T') fst.push_back(x);
    else            sec.push_back(x);
  }
  sec.push_back(1000);

  sort(all(fst), greater<int>());
  sort(all(sec), greater<int>());

  double cnt = 0, d = 0, t = 0;
  while (fst.size() && sec.size()) {
    double v = 1.0 / (cnt + 1);

    double nxtTime = fst.back();
    double nxtDist = sec.back();
    double canTrav = d + (nxtTime - t) * v;

    if (canTrav - nxtDist > EPI) {
      t = t + (nxtDist - d) / v;
      d = nxtDist;
      sec.pop_back();
    } else {
      t = nxtTime;
      d = canTrav;
      fst.pop_back();
    }

    ++cnt;
  }

  while (fst.size()) {
    double v = 1.0 / (cnt + 1);
    double nxtTime = fst.back();
    double canTrav = d + (nxtTime - t) * v;
    t = nxtTime;
    d = canTrav;
    ++cnt;
    fst.pop_back();
  }

  while (sec.size()) {
    double v = 1.0 / (cnt + 1);
    double nxtDist = sec.back();
    t = t + (nxtDist - d) / v;
    d = nxtDist;
    ++cnt;
    sec.pop_back();
  }

  cout << (ll)round(t) << endl;
} 

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  if (fopen(file".in", "r")) {
      freopen(file".in", "r", stdin);
      freopen(file".out", "w", stdout);
  }

  int t=1;
  // cin >> t;
  for(int i=1; i<=t; ++i)
      uraqt();
}

