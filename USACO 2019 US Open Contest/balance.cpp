// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define vec vector
#define ll long long
#define ii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int N = 2e5+5;

int n;
vector<int> lb[2], rb[2];
ll invl, invr;

void solve() {
	cin >> n;

	for(int i=1; i<=n; ++i) {
		int x;
		cin >> x;
		if (x == 0) invl += lb[1].size();
		lb[x].push_back(i);
	}

	for(int i=1; i<=n; ++i) {
		int x;
		cin >> x;
		if (x == 0) invr += rb[1].size();
		rb[x].push_back(i);
	}

	ll ans = abs(invl - invr);
	
	// cout << invl << " "   << invr << "\n";
	// Pattern 0 1
	ll tmp1 = invl, tmp2 = invr, moving = 0;
	for(int rep=0; rep<min(sz(lb[0]), sz(rb[1])); ++rep) { 
		int pos0 = lb[0].back();
		moving += n - pos0;
		int pos1 = rb[1][rep];
		moving += pos1-1;

		tmp1 -= pos0 - sz(lb[0]);
		tmp2 -= (n - pos1 + 1) - (sz(rb[1]) - rep);
		ans = min(ans, abs(tmp1 - tmp2) + rep + 1 + moving);
		// cout << tmp1 << " " << tmp2 << "\n";

		lb[0].pop_back();
	}

	// Pattern 1 0
	tmp1 = invl; tmp2 = invr; moving = 0;
	for(int rep=0; rep<min(sz(lb[1]), sz(rb[0])); ++rep) {
		int pos1 = lb[1].back();
		moving += n - pos1;
		lb[1].pop_back();
		int pos0 = rb[0][rep];
		moving += pos0 - 1;

		tmp1 -= (n - pos1);
		tmp2 -= (pos0 - 1);

		tmp1 += sz(lb[1]);
		tmp2 += sz(rb[0])-rep-1;
		
		ans = min(ans, abs(tmp1 - tmp2) + rep + 1 + moving);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen("balance.in", "r")) {
		freopen("balance.in", "r", stdin);
		freopen("balance.out", "w", stdout);
	}

	solve();
	return 0;
}
