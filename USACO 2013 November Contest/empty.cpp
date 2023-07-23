// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define C make_pair
#define forn(i, n) for(int i=1; i<=n; ++i)
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)

const int nax = 3e6+3;
int n, k, cnt[nax], e[nax], mx[nax];
bool used[nax];

int root(int u) {
	return e[u] < 0 ? u : e[u] = root(e[u]);
}

void join(int u, int v) {
	if ((u = root(u)) == (v = root(v)))
		return;
	if (e[u] > e[v]) swap(u, v);
	e[u] += e[v];
	mx[u] = max(mx[u], mx[v]);
	e[v] = u;
}

void solve() {
	cin >> n >> k;

	foru(i, 0, n) {
		e[i] = -1;
		mx[i] = i-1;
	}

	foru(i, 1, k) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		foru(j, 1, y) {
			int num = (1LL*a*j % n + b) % n;
			cnt[num] += x;
		}
	}

	foru(i, 0, n-1) {
		foru(j, 1, cnt[i]) {
			int nxt = mx[root(i)] + 1;
			if (nxt == n) nxt = mx[root(0)] + 1;

			used[nxt] = 1;
			mx[nxt] = nxt;

			if (nxt > 0) if (used[nxt-1]) join(nxt, nxt-1);
			if (nxt < n-1) if (used[nxt+1]) join(nxt, nxt+1);
		}
	}

	foru(i, 0, n-1) {
		if (!used[i]) {
			cout << i;
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen("empty.in", "r")) {
		freopen("empty.in", "r", stdin);
		freopen("empty.out", "w", stdout);
	}

	solve();
	return 0;
}