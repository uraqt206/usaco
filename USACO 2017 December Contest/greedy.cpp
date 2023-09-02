#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
template<class T> using vec = vector<T>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define file "greedy"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, c[N];

int earn[N], in[N];

int brute() {
  foru(i, 1, n) {
    in[i] = i;
  }

  foru(r, 1, 15) {
    earn[in[1]] = 1;
    int leap = c[in[1]], at = in[1];
    foru(i, 1, n-leap-1) in[i] = in[i+1];
    in[n-leap] = at;
    // foru(i, 1, n) {
    //   cout << in[i] << " ";
    // }
    // cout << "\n";
  }

  int ans = 0;
  foru(i, 1, n) if (!earn[i]) ans+=1;
  return ans;
}

bool check(int x) {
  vec<int> cows;
  foru(i, 1, x-1) cows.push_back(c[i]);
  sort(all(cows));
  int cur = n-x+1;
  fore(v, cows) {
    if (v >= cur) return 0;
    cur += 1;
  }
  return 1;
}

int main() {
  setIO();

  cin >> n;
  foru(i, 1, n) cin >> c[i];

  int ans = 0;
  for(int z=n>>1; z>=1; z>>=1)
    while (ans+z <= n && check(ans+z))
      ans += z;
  
  cout << n-ans;
}