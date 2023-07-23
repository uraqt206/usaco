/* Trust The Process */

#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl
#define fr(i,l,r) for(int i=(l); i<=(r); ++i)
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
#define file "censor"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

void read() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
      freopen(file".in", "r", stdin);
      freopen(file".out", "w", stdout);
  }
}

const int mxN = 1e6 + 10, B = 256, M = 1e9 + 7;
vt<int> pw(mxN), hsh{0};
int hshT;
string S, T;

int get(int L, int R) {
  return (hsh[R] - (1LL * hsh[L-1] * pw[R - L + 1] % M) + M) % M;
}

void solve() {
  pw[0] = 1;
  for(int i=1; i<mxN; ++i)
    pw[i] = (1LL * pw[i-1] * B) % M;

  cin >> S >> T;

  for(char ch: T)
    hshT = (1LL * hshT * B + ch) % M;

  string R;
  for(char ch: S) {
    R.push_back(ch);
    hsh.push_back((1LL * hsh.back() * B + ch) % M);

    if (R.size() >= T.size()) {
      if (get(R.size() - T.size() + 1, R.size()) == hshT) {
        R.resize(R.size() - T.size());
        hsh.resize(hsh.size() - T.size());
      }
    }
  }
  cout << R;
}

int main() {
  read();
  solve();
  return 0;
}
