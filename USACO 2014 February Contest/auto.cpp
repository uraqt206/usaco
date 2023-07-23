#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmax(T &A, const T B) {
	if (A < B) {
		A = B;
		return 1;
	}
	return 0;
}

template<class T> bool ckmin(T &A, const T B) {
	if (A > B) {
		A = B;
		return 1;
	}
	return 0;
}

#define vt vector
#define C make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define file "auto"

void read() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
}

const int mxn = 1001;
vt<pair<string, int>> a;

bool check(string a, string b) {
	if (a.size() > b.size()) return 0;
	for(int i=0; i<a.size(); ++i) if (a[i] != b[i])
		return 0;
	return 1;
}

int N, Q;

void solve() {
	cin >> N >> Q;

	for(int i=1; i<=N; ++i) {
		string tmp;
		cin >> tmp;
		a.push_back(C(tmp, i));
	}
	sort(all(a));

	for(int q=1; q<=Q; ++q) {
		int k;
		string t;
		cin >> k >> t;

		int lb = 1, rb = N + 1, mb;
		while (lb < rb) {
			mb = (lb + rb) >> 1;
			if (a[mb - 1].fi >= t) rb = mb;
			else lb = mb + 1;
		}

		if (lb + k - 1 > N) {
			cout << "-1\n";
			continue;
		}

		if (check(t, a[lb + k - 2].fi))
			cout << a[lb + k - 2].se << endl;
		else
			cout << "-1\n";

		// cout << "CHO\n";
	}
}

int main() {
	read();
	solve();
	return 0;
}