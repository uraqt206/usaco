#include <bits/stdc++.h>

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << "\n"
#define go(i,l,r) for(int i=(l); i<=(r); ++i)
#define rev(i,l,r) for(int i=(r); i>=(l); --i)
#define each(i, v) for(auto &i: v)
#define x first
#define y second
#define vec vector
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "censor"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mxN = 1e5+5, M = 1e9+9277, B = 256;
string s;
int n, m, pw[mxN];
set<int> exist;
vec<int> len;

void prep() {
	pw[0] = 1;
	for(int i=1; i<=n; ++i) pw[i] = (1LL * pw[i-1] * B) % M;
	go(i, 1, m) {
		string t; cin >> t;
		len.push_back(sz(t));
		int hsh = 0;
		each(ch, t) hsh = (1LL * hsh * B + ch) % M;
		exist.insert(hsh);
	}
	sort(all(len));
	uni(len);
}

void solve() {
	cin >> s >> m; n = s.size();
	prep();
	string ret{0};
	vec<int> hsh{0};
	each(c, s) {
		ret.push_back(c);
		hsh.push_back((1LL * hsh.back() * B + c) % M);
		each(l, len) {
			if (l >= sz(ret)) break;
			int val = (hsh.back() - (1LL * hsh[sz(hsh)-l-1] * pw[l]) % M + M) % M;
			if (exist.count(val)) {
				hsh.resize(hsh.size() - l);
				ret.resize(ret.size() - l);
				break;
			}
		}
	}
	for(int i=1; i<ret.size(); ++i) cout << ret[i];
}

conqueror_of_uraqt {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	solve();
	return 0;
}