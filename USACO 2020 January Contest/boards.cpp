#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool ckmin(T &a, const T b) { if (a>b) return a=b, 1; return 0; }
template<class T> bool ckmax(T &a, const T b) { if (a<b) return a=b, 1; return 0; }

// debug things
#define deb(x) cout << #x << ": " << x << "\n"
#define bitmask(i, j) cout << bitset<j>(i) << "\n"
#define xuong cout << "--------------------\n";

// stuff
#define vt vector
#define fi first
#define se second
#define rep(i, l, r) for(int i=(l); i<=(r); ++i)
#define fod(i, l, r) for(int i=(r); i>=(l); --i)
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define sz(x) (int)x.size()
#define C make_pair

struct event {
	int x, y, t, id;
	event(int _x=0, int _y=0, int _id=0, int _t=0) : x(_x), y(_y), id(_id), t(_t) {}
	bool operator<(const event b) const {
		if (x^b.x) return x<b.x;
		if (y^b.y) return y<b.y;
		return t;
	}
};

ll n, m, p;
vt<ll> cmp{0}, sgt, dp;
vt<event> evts;

#define lc id<<1
#define rc id<<1|1

void upd(int id, int lb, int rb, int k, ll v) {
	if (lb == rb) {
		ckmin(sgt[id], v);
		return;
	}
	int mb = (lb+rb) >> 1;
	if (k <= mb) upd(lc, lb, mb, k, v);
	else upd(rc, mb+1, rb, k, v);	
	sgt[id] = min(sgt[lc], sgt[rc]);
}

ll query(int id, int lb, int rb, int r) {
	if (lb > r) return 1e13;
	if (rb <= r) return sgt[id];
	int mb = (lb + rb) >> 1;
	return min(query(lc, lb, mb, r), query(rc, mb+1, rb, r));
}

int pos(int x) {
	return upper_bound(all(cmp), x) - cmp.begin();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);

	cin >> n >> p;

	rep(i, 1, p) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		evts.push_back(event(u, v, i, 0));
		evts.push_back(event(x, y, i, 1));
		cmp.push_back(v); cmp.push_back(y);
	}

	sort(all(cmp));
	uni(cmp);
	m = sz(cmp);
	sort(all(evts));

	sgt = vt<ll>(4*m+1, 1e13);
	dp = vt<ll>(p+1, 1e13);

	upd(1, 1, m, 1, 0);

	for(auto cur: evts)
		if (cur.t)
			upd(1, 1, m, pos(cur.y), dp[cur.id] - cur.x - cur.y);
		else
			dp[cur.id] = query(1, 1, m, pos(cur.y)) + cur.x + cur.y;

	cout << query(1, 1, m, m) + n + n;
}
