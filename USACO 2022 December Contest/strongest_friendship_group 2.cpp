#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int lim = 2e9;
const int N = 1e5+5;

int n, m, cnt[N], siz[N];
vector<int> graph[N], order;

int e[N];

int root(int u) {
	return e[u] < 0 ? u : e[u] = root(e[u]);
}

void join(int u, int v) {
	if ((u = root(u)) == (v = root(v)))
		return;
	if (e[u] > e[v]) swap(u, v);
	e[u] += e[v];
	e[v] = u;
}

int deg[N];
set<ii> tmp;
bool proc[N];

void solve() {
	cin >> n >> m;
	memset(e, -1, sizeof(e));

	for(int i=1; i<=m; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1; i<=n; ++i) {
		deg[i] = graph[i].size();
		tmp.insert({deg[i], i});
	}

	for(int i=0; i<n; ++i) {
		auto it = *tmp.begin();

		int u = it.se;
		order.push_back(u);
		proc[u] = 1;
		cnt[i] = it.fi;

		for(int v : graph[u]) if (!proc[v]) {
			tmp.erase({deg[v], v});
			--deg[v];
			tmp.insert({deg[v], v});
		}

		tmp.erase(it);
	}

	memset(proc, 0, sizeof(proc));
	ll ans = 0;

	for(int i=n-1; i>=0; --i) {
		int u = order[i];
		proc[u] = 1;

		for(int v : graph[u]) if (proc[v]) {
			join(u, v);
		}

		ans = max(ans, 1LL * cnt[i] * -e[root(u)]);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}