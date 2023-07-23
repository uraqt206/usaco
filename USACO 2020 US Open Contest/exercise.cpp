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
#define file "exercise"
 
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(file".in", "r")) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
  }
}

const int N = 1e5+5;
int n, MOD;
bool comp[N];
vector<int> prime;

void add(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mul(int a, int b) { return 1LL * a * b % MOD; }

void prep() {
  comp[0] = comp[1] = 1;
  foru(i, 2, n) {
    if (comp[i] == 0) prime.push_back(i);
    fore(x, prime) {
      if (1LL * i * x > n) break;
      comp[i * x] = 1;
      if (i % x == 0) break;
    }
  }
}

set<int> s;
int ans1, ans2;

void backtrack(int used, int lcm, int current) {
  if (used == n && current == 0) { s.insert(lcm); return; }
  if (current > 0) { backtrack(used, lcm / __gcd(lcm, current) * current, 0); }
  if (used < n) { backtrack(used+1, lcm, current+1); }
}

void brute() {
  backtrack(0, 1, 0);
  fore(x, s) add(ans1, x);
  cout << ans1;
}

int dp[1300][10001], pre[1300][10001];

void knapsack() {
  dp[0][0] = 1;

  foru(i, 0, sz(prime)-1) {
    foru(j, 0, n) {
      dp[i+1][j] = dp[i][j];
    }

    foru(j, 0, n) {
      int value = prime[i];
      while (value <= j) {
        add(dp[i+1][j], mul(value, dp[i][j-value]));
        value *= prime[i];
      }
    }
  }

  foru(i, 0, n) add(ans2, dp[sz(prime)][i]);
  cout << ans2;  
}

int main() {
  setIO();
  cin >> n >> MOD;
  prep();

  if (n <= 10) brute();
  else knapsack();
}