#include <bits/stdc++.h>

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << "\n"
#define go(i,l,r) for(int i=(l); i<=(r); ++i)
#define rev(i,l,r) for(int i=(r); i>=(l); --i)
#define x first
#define y second
#define vec vector
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "hopscotch"

template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int mod = 1e9+7;

struct ds {
	int n;
	vec<int> ft;
	ds(int _n=0) : n(_n) {
		ft = vec<int>(n+1);
	}
	void upd(int i, int v) {
		for(; i<=n; i+=i&-i) ft[i] = (ft[i] + v) % mod;
	}
	int query(int i) {
		int ans = 0;
		for(; i>=1; i-=i&-i) ans = (ans + ft[i]) % mod;
		return ans;
	}
};

int neg(int a, int b) {
	a -= b;
	if (a < 0) a += mod;
	return a;
}

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int n, m, k, a[751][751], tmp[751][751], dp[751][751];

void solve() {
	cin >> n >> m >> k;
	vec<ds> ft(k+1);
	vec<vec<int>> pre(k+1);
	go(i, 1, n) {
		go(j, 1, m) {
			cin >> a[i][j];
			pre[a[i][j]].push_back(j);
		}
	}
	go(i, 1, k) {
		sort(all(pre[i]));
		uni(pre[i]);
		ft[i] = ds(sz(pre[i]));
	}
	tmp[1][1] = 1; dp[1][1] = 1;
	go(i, 1, n) {
		go(j, 1, m) {
			if (i==1 && j==1) continue;
			int v = a[i][j];
			int p = lower_bound(all(pre[v]), j) - pre[v].begin();
			tmp[i][j] = dp[i-1][j-1];
			tmp[i][j] = neg(tmp[i][j], ft[v].query(p));
			dp[i][j] = neg(add(add(tmp[i][j], dp[i-1][j]), dp[i][j-1]), dp[i-1][j-1]);
		}
		go(j, 1, m) {
			int v = a[i][j];
			int p = upper_bound(all(pre[v]), j) - pre[v].begin();
			ft[v].upd(p, tmp[i][j]);
		}
	}
	// go(i, 1, n) {
	// 	go(j, 1, m) {
	// 		cout << tmp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	cout << tmp[n][m];
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