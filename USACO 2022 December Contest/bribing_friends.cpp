#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define fi first
#define se second
#define ins push_back
#define vec vector
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

struct friends {
	int p, c, x;
	friends(int _p=0, int _c=0, int _x=0) : p(_p), c(_c), x(_x) {}

	bool operator < (const friends &f) { return x < f.x; }
};

const int nx = 2002;
int n, a, b;
vec<friends> info;

int type(int x, int y) {
	return b-y + a-x;
}

int dp[nx][nx*2];
int go(int i, int ca, int cb) {
	if (i == n) return 0;
	int &val = dp[i][type(ca, cb)];
	if (val != -1) return val;

	val = go(i+1, ca, cb);

	auto [p, c, x] = info[i];
	int disc = min(cb/x, c);
	
	int need = c - disc;
	if (disc < c) { if (ca >= need) val = max(val, p + go(i+1, ca-need, 0)); }
	else val = max(val, p + go(i+1, ca, cb - disc*x));

	// cout << i << " " << ca << " " << cb << " : " << val << "\n";
	return val;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> a >> b;

	foru(i, 1, n) {
		int p, c, x;
		cin >> p >> c >> x;
		info.emplace_back(p, c, x);
	}
	
	// ford(j, b, 0) cout << type(a, j) << "\n";
	// ford(i, a, 0) cout << type(i, 0) << "\n";
	sort(all(info));
	cout << go(0, a, b);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
}
