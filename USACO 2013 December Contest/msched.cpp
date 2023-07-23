/*
USACO 2013 December Contest, Silver
Problem 1. Milk Scheduling

Link: http://usaco.org/index.php?page=viewproblem2&cpid=361
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (en); i>=(be); --i)
#define fi first
#define se second
#define vt vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define file "msched"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

int N;
vt<int> cows[10001];

void underated() {
  cin >> N;

  rep(i, 1, N) {
    int r, x;
    cin >> x >> r;
    cows[r].push_back(x);
  }

  int sum = 0;
  priority_queue<int, vt<int>, greater<int>> pq;
  rep(i, 1, 10000) {
    for(int x: cows[i]) {
      pq.push(x);
      sum += x;

      if (sz(pq) > i) {
        sum -= pq.top();
        pq.pop();
      }
    }
  }

  cout << sum;
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
