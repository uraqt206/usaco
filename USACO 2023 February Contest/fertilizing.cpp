// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define vec vector
#define ins push_back
#define all(x) (x).begin(), (x).end()
#define foru(i, l, r) for(int i=(l); i<=(r); ++i)
#define ford(i, l, r) for(int i=(l); i>=(r); --i)
#define fore(i, v) for(auto &i : v)

const ll lim = 4e18;
const int nax = 2e5+5;
int n, t, a[nax], mx[nax];
ll f[nax], g[nax], sum[nax], cnt[nax];
vec<int> tree[nax];

// f[u]: solve root u for t = 0
// g[u]: solve root u for t = 1

void dfs(int u) {
	sum[u] = a[u];
	cnt[u] = 1;
	
	fore(v, tree[u]) {
		dfs(v);
		sum[u] += sum[v];
		cnt[u] += cnt[v];
		mx[u] = max(mx[u], mx[v] + 1);
	}
	
	sort(all(tree[u]), [&](int x, int y) {
		return sum[y] * cnt[x] <= sum[x] * cnt[y];
	});

	ll total = 0, totalT = 0, timers = 0, pref = 0;
	fore(v, tree[u]) {
		f[u] += f[v] + sum[v] * (timers + 1);
		timers += cnt[v] * 2;
		total += sum[v];
	}
	totalT = timers;

	g[u] = lim;
	if (tree[u].empty()) g[u] = 0;

	timers = 0;
	fore(v, tree[u]) {
		pref += sum[v];
		if (mx[v] == mx[u]-1) {
			ll val = f[u];
			val -= f[v] + sum[v] * (timers + 1);
			val -= (total - pref) * (cnt[v] * 2);
			val += g[v] + sum[v] * (totalT - cnt[v] * 2 + 1);
			g[u] = min(g[u], val);
		}
		timers += cnt[v] * 2;
	}

	// cout << "Node " << u << ": " << g[u] << "\n";
}

void solve() {
	cin >> n >> t;	
	foru(i, 2, n) {
		int p;
		cin >> p >> a[i];
		tree[p].ins(i);
	}

	dfs(1);

	if (t == 0) cout << 2 * (n-1) << " " << f[1];
	else cout << 2 * (n-1) - mx[1] << " " << g[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}
