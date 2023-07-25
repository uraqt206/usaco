#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

#define vec vector
#define foru(i, l, r) for(int i=l; i<=r; ++i)
#define revu(i, r, l) for(int i=r; i>=l; --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()

const int lim = 2e9;
const int N = 1e5+5;

int n, cnt, moo[N], nxt[N];
int id[N], mn[N];
ll ans;

void solve() {
	cin >> n;

	for(int i=1; i<=n; ++i) {
		cin >> nxt[i] >> moo[i];
		ans += moo[i];
	}

	fill(id, id+n+1, -2);
	fill(mn, mn+n+1, lim);

	for(int i=1; i<=n; ++i) if (id[i] == -2) {
		vector<int> path;

		int at = i;
		while (id[nxt[at]] == -2) {
			id[at] = -3;
			path.push_back(at);
			at = nxt[at];
		}
		path.push_back(at);

		bool in_cycle = 0;
		for(int j : path) {
			in_cycle |= (j == nxt[at]);
			if (in_cycle) mn[cnt] = min(mn[cnt], moo[j]);
		}

		cnt += in_cycle;
	}

	for(int i=0; i<cnt; ++i)
		ans -= mn[i];
	
	cout << ans;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);


		//freopen(".in", "r", stdin);
		//freopen(".out", "w", stdout);

		solve();
		return 0;
}
