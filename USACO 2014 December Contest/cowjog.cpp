#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using db =  double;

#define conqueror_of_uraqt int main()
#define xuong cout << "\n"
#define debug(x) cout << #x << ": " << x << endl
#define rep(i,be,en) for(int i = (be); i<=(en); ++i)
#define fod(i,be,en) for(int i = (be); i>=(en); --i)
#define each(x, a)   for(auto &x: a)
#define x first
#define y second
#define vec vector
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define uni(a) ((a).erase(unique(all(a)),(a).end()))
#define C make_pair
#define file "cowjog"

const int mod = 1e9+7;
template<class T> bool ckmax(T &a, T b) {if (a<b) return a=b,1; return 0;}
template<class T> bool ckmin(T &a, T b) {if (a>b) return a=b,1; return 0;}
int add(int a, int b) { a+=b; if (a>=mod) a-=mod; return a; }
int neg(int a, int b) { a-=b; if (a<0) a+=mod; return a; }
int mul(int a, int b) { return (1LL*a*b) % mod; }

const db eps = 0.0000000001;
const int INF = 1e9+9;
const ll LINF = 1e18+8;
const int M[2] = {(int)1e9+9277, (int)1e9+5277}, mxN = 1e5+5;

void work() {
	int n, t;
	cin >> n >> t;
	vec<ll> a;
	for(int i=1; i<=n; ++i) {
		int p, v;
		cin >> p >> v;
		a.push_back(p + 1LL*v*t);
	}	

	vec<ll> dp(n+1, -LINF);
	dp[0] = LINF;
	for(int i=0; i<n; ++i) {
		int lb = 0, rb = i, mb;
		while (lb < rb) {
			mb = (lb + rb + 1) >> 1;
			if (dp[mb] >= a[i])
				lb = mb;
			else
				rb = mb-1;
		} 
		dp[lb+1] = a[i];
	}

	for(int i=n; i>=0; --i) if (dp[i] > -LINF) {
		cout << i;
		return;
	}
}

conqueror_of_uraqt {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen(file".in", "r")) {
		freopen(file".in", "r", stdin);
		freopen(file".out", "w", stdout);
	}
	work();
	return 0;
}