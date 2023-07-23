#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
 
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(x, v) for(auto &x : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define file "walk"
 
void setIO(string name="") {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 7501, MOD = 2019201997, X = 2019201913, Y = 2019201949;
int n, k;
int dist[N], mn[N];
vector<int> take;
bool inMst[N];

int wei(int i, int j) {
  if (i > j) swap(i, j);
  return (1LL * i * X % MOD + 1LL * j * Y % MOD) % MOD;
}

int main() {
  setIO();

  cin >> n >> k;

  foru(i, 1, n) {
    dist[i] = mn[i] = INT_MAX;
  }

  int st = 1;
  foru(i, 2, n) dist[i] = wei(st, i);

  foru(i, 1, n-1) {
    st = -1;
    foru(j, 1, n) if (!inMst[j] && (st == -1 || dist[st] > dist[j])) st = j;
    take.push_back(dist[st]);
    inMst[st] = 1;
    foru(j, 1, n) if (!inMst[j]) dist[j] = min(dist[j], wei(j, st)); 
  }

  sort(all(take));
  cout << take[n-k];
} 