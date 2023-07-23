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
#define file "cowpatibility"

using namespace std;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;

template<class T> bool maximize(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool minimize(T &a, T b) {if (a>b) return a=b,1; return 0;}

const int mod = 1e9 + 7;
const int mxn = 2e5 + 5;

void read() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen(file".in", "r")) {
      freopen(file".in", "r", stdin);
      freopen(file".out", "w", stdout);
  }
}

int N;
vt<vt<int>> V;

void uraqt() {
  cin >> N;

  for(int i=1; i<=N; ++i) {
    vt<int> cows(5);
    for(int &j: cows) cin >> j;
    sort(all(cows));

    for(int m=1; m<32; ++m) {
      vt<int> tmp;
      for(int j=0; j<5; ++j) if (m>>j&1)
        tmp.push_back(cows[j]);
      V.push_back(tmp);
    }
  }

  ll total = 1LL * N * (N - 1) / 2;
  sort(all(V));
  for(int i=0, cnt=1; i<V.size(); ++i) {
    if (V[i] != V[i+1]) {
      ll sum = (1LL * cnt * (cnt - 1)) / 2;
      if (V[i].size() & 1) total -= sum;
      else total += sum;
      cnt = 1;
    } else ++cnt;
  }

  cout << total;
}

int main() {
  read();
	int t = 1;
	// cin >> t;
	for(int i=1; i<=t; ++i)
		uraqt();
}
