// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define file "squares"

const int INF = 1e9;
const int nax = 50001;
int n, k;
set<pair<int, int>> active;
vec<pair<pair<int, int>, int>> evts;
pair<int, int> a[nax];

void solve() {
	cin >> n >> k;

	pair<int, int> sus;

	for(int i=1; i<=n; ++i) {
		cin >> a[i].first >> a[i].second;
		evts.ins({a[i], i});
	}

	sort(evts.begin(), evts.end());
	int j=0;

	for(int i=0; i<n; ++i) {
		int dx = evts[i].first.first, dy = evts[i].first.second;
		int idx = evts[i].second;

		while (evts[j].first.first <= dx - k) {
			active.erase({evts[j].first.second, evts[j].second});
			++j;
		}

		auto lb = active.upper_bound({dy - k, INF});
		
		if (lb != active.end() && lb->first < dy + k) {
			// cout << dx << " " << dy << " " << lb->first << "\n";
			if (sus.first > 0) {
				cout << "-1\n";
				return;
			} else sus = {lb->second, idx};
		}

		active.insert({dy, idx});
	}

	if (sus.first == 0) cout << "0\n";
	else {
		int i1 = sus.first, i2 = sus.second;
		cout << 1LL * (k - abs(a[i2].first - a[i1].first)) * (k - abs(a[i2].second - a[i1].second));
	}
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	
	solve();
	return 0;
}