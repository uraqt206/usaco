#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmin(T &a, const T b) { 
	if (a>b) return a=b, 1; return 0;
}

template<class T> bool ckmax(T &a, const T b) {
	if (a<b) return a=b, 1; return 0;
}

#define deb(x) cout << #x << ": " << x << "\n"
#define bitmask(i, j) cout << bitset<j>(i) << "\n"
#define xuong cout << "--------------------\n";
#define vt vector
#define fi first
#define se second
#define rep(i, l, r) for(int i=(l); i<=(r); ++i)
#define fod(i, l, r) for(int i=(r); i>=(l); --i)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define C make_pair

const int INF = 2e9;
int n, m, nxt[100100], prv[100100];
vt<pair<pii, int>> boots;
vt<pii> a;
bool ans[100010];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	cin >> n >> m;

	rep(i, 1, n) {
		int s;
		cin >> s;
		a.push_back(C(s, i));
		nxt[i] = i+1;
		prv[i] = i-1;
	}

	rep(i, 1, m) {
		int s, d;
		cin >> s >> d;
		boots.push_back(C(C(s, d), i));
	}
	
	sort(all(a), greater<pii>());
	sort(all(boots), greater<pair<pii, int>>());
	
	int i=0, j=0, nax=1;
	while (i < m) {
		auto tmp = boots[i];
		int s = boots[i].fi.fi, d = boots[i].fi.se;
		int p = boots[i].se;
		
		while (j < n && a[j].fi > s) {
			int idx = a[j].se;

			prv[nxt[idx]] = prv[idx];
			nxt[prv[idx]] = nxt[idx];
			ckmax(nax, nxt[idx] - prv[idx]);
			++j;
		}
		
		//cout << nax << endl;
		if (nax <= d) ans[p] = 1;
		++i;
	}

	rep(i, 1, m) cout << ans[i] << "\n";
}
