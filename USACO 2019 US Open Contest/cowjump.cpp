// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vec vector
#define ins push_back
#define C make_pair
#define file "cowjump"

struct point {
	ll x, y;
	point(ll _x=0, ll _y=0) : x(_x), y(_y) {}
	ll friend operator * (const point a, const point b) {
		return a.x*b.y - a.y*b.x;
	}
	bool friend operator == (const point a, const point b) {
		return C(a.x, a.y) == C(b.x, b.y);
	}
	point friend operator - (const point a, const point b) {
		return point(a.x-b.x, a.y-b.y);
	}
};

struct segment {
	point p, q;
	segment(point _p = {0, 0}, point _q = {0, 0}) : p(_p), q(_q) {}
};

const int nax = 1e5+5;
int n;
segment a[nax];
set<pair<ll, int>> active;
vec<pair<point, int>> evts;
pair<int, int> sus;

bool cmp(pair<point, int> u, pair<point, int> v) {
	return C(u.first.x, u.first.y) < C(v.first.x, v.first.y);
}

int sign(point x, point y, point u) {
	ll cross = (u-x) * (y-x);
	if (cross < 0) return -1;
	if (cross == 0) return 0;
	return 1;
}

bool contain(point x, segment v) {
	return x.x >= min(v.p.x, v.q.x) && x.x <= max(v.p.x, v.q.x)
			&& x.y >= min(v.p.y, v.q.y) && x.y <= max(v.p.y, v.q.y);
}

bool intersect(segment u, segment v) {
	vec<ll> val;
	val.ins(sign(u.p, u.q, v.p));
	val.ins(sign(u.p, u.q, v.q));
	if (val[0] == val[1] && val[1] == 0) return contain(u.p, v) || contain(u.q, v) || contain(v.p, u);
	val.ins(sign(v.p, v.q, u.p));
	val.ins(sign(v.p, v.q, u.q));
	return val[0] != val[1] && val[2] != val[3];
}

int dem(segment x) {
	int cnt=0;
	for(int i=1; i<=n; ++i)
		cnt += intersect(x, a[i]);
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}

	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i].p.x >> a[i].p.y >> a[i].q.x >> a[i].q.y;
		evts.ins(C(a[i].p, i));
		evts.ins(C(a[i].q, i));
	}

	sort(evts.begin(), evts.end(), cmp);
	for(int i=0; i<2*n; ++i) {
		int idx = evts[i].second;
		point p = evts[i].first;
		// cout << evts[i].first.x << " " << evts[i].first.y << " " << evts[i].second << "\n";

		point other = (p == a[idx].p ? a[idx].q : a[idx].p);
		if (active.find(C(other.y, idx)) != active.end()) {
			auto it = active.find(C(other.y, idx));
			if (it != active.begin() && next(it) != active.end()) {
				auto prv = *prev(it);
				auto nxt = *next(it);
				if (intersect(a[prv.second], a[nxt.second])) {
					sus = C(prv.second, nxt.second);
					break;
				}
			}
			active.erase(it);
		} else {
			active.insert(C(p.y, idx));
			auto it = active.find(C(p.y, idx));

			if (it != active.begin()) {
				auto prv = *prev(it);
				if (intersect(a[prv.second], a[idx])) {
					sus = C(prv.second, idx);
					break;
				}
			} 

			if (next(it) != active.end()) {
				auto nxt = *next(it);
				if (intersect(a[nxt.second], a[idx])) {
					sus = C(nxt.second, idx);
					break;
				}
			}
		}
	}	

	if (sus.first > sus.second) swap(sus.first, sus.second);
	int cnt1 = dem(a[sus.first]);
	int cnt2 = dem(a[sus.second]);

	if (cnt1 >= cnt2) cout << sus.first;
	else cout << sus.second;
}