#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define mask(i) (1 << (i))

int t, n;
bool can[61][1 << 20];
int rep[20][61];

int str_to_num(string s) {
  int ret = 0;
  for(int i = 0; i < n; ++i) if (s[i] == '1')
    ret ^= (1 << i);
  return ret;
}

int shift(int num) {
  if (num & mask(n-1))
    return (num - mask(n-1)) * 2 + 1;
  return num * 2;
}

void prep() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n*3; ++j) {
      int bit = (i + j) % n;
      rep[i][j + 1] = rep[i][j] ^ mask(bit);
    }
  }

  can[0][0] = 1;
  for(int i = 0; i < n*3; ++i) {
    // cout << "I " << i << "\n";
    for(int j = 0; j < mask(n); ++j) if (can[i][j]) {
      // cout << bitset<3>(j) << "\n";
      for(int z = 0; z < n; ++z) {
        can[i + 1][j ^ rep[z][i+1]] = 1;
      }
    }
  }
}

void solve() {
  cin >> t >> n;
  prep();

  for(int c = 0; c < t; ++c) { 
     string s, t;
     cin >> s >> t;

    int lights = str_to_num(s);
    int switchs = str_to_num(t);

    int cur = switchs;
    for(int i = 0; i <= n*3; ++i) {
      if (can[i][lights]) {
        cout << i << "\n";
        break;
      }

      lights ^= cur;
      cur = shift(cur);
    }
  }
}

signed main() {
	ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  if (fopen("input.inp", "r")) {
    freopen("input.inp", "r", stdin);
    freopen("input.out", "w", stdout);
  }

  solve();
}
